
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

//CODE
#define SERVER_PORT 9999
#define BUFF_LEN 512
#define SERVER_IP "127.0.0.1"

int main(int argc, char** argv)
{
  int receive_fd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in ser_addr;

  if(receive_fd < 0)
  {
    printf("Create socket fail!\n");
    return -1;
  }

  memset(&ser_addr, 0, sizeof(ser_addr));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ser_addr.sin_port = htons(SERVER_PORT);

  int ret = bind(receive_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
  if(ret < 0)
  {
    printf("socket bind fail!\n");
    return -1;
  }

  {
    socklen_t len;
    struct sockaddr_in client_addr;
    char buff[BUFF_LEN];
    while(1)
    {
      memset(buff, 0, BUFF_LEN);
      len = sizeof(client_addr);
      auto count = recvfrom(receive_fd, buff, 11, 0, (struct sockaddr*)&client_addr, &len);
      if(count == -1)
      {
        printf("Receive data fail!\n");
        return -1;
      }

      printf("client:%s\n", buff);
      memset(buff, 0, BUFF_LEN);
      sprintf(buff, "I have received %ld bytes data!\n", count);
      printf("server: %s\n", buff);
    }

  }

  close(receive_fd);

  return 0;
}

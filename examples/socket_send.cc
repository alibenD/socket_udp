/**-----------------------------------------------
  * @Copyright (C) 2021 All rights reserved.
  * @file: socket_send.cc
  * @version: v0.0.1
  * @author: aliben.develop@gmail.com
  * @create_date: 2021-11-30 20:38:21
  * @last_modified_date: 2021-11-30 20:52:43
  * @brief: TODO
  * @details: TODO
  *-----------------------------------------------*/

//INCLUDE
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
  int sender_fd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in ser_addr;

  if(sender_fd < 0)
  {
    printf("Create socket fail!\n");
    return -1;
  }

  memset(&ser_addr, 0, sizeof(ser_addr));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  ser_addr.sin_port = htons(SERVER_PORT);

  {
    socklen_t len;
    while(1)
    {
      //char buff[BUFF_LEN] = "test udp msg\n";
      char buff[BUFF_LEN] = "0123456789\n";
      len = sizeof(ser_addr);
      sendto(sender_fd, buff, strlen(buff), 0, (struct sockaddr*)&ser_addr, len);
      sleep(1);
    }

  }

  close(sender_fd);

  return 0;
}

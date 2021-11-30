/**-----------------------------------------------
  * @Copyright (C) All rights reserved.
  * @filename: DummyTest.cc
  * @author: aliben.develop@gmail.com
  * @created_date: 2021-11-30 20:38:01
  * @last_modified_date: NO_LAST_MODIFIED_DATE
  * @description: TODO
  *-----------------------------------------------*/

//INCLUDE
#include <socket_udp/dummy_test.hh>
#include <gtest/gtest.h>

//CODE

using namespace Demo;

TEST(DummyTest, Empty)
{
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

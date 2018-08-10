//------------------------------------------------------------------------------
// Copyright (c) 2018, Ilya Kotelnikov (ilya.kotelnikov@gmail.com), independent
// researcher. All rights reserved.
//
// You may use, distribute and modify this code under the terms of GNU GPLv3.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <vector>

int main() {
  printf("hello, world!\n");

  std::vector<int> v({1,2,3});
  for(auto& a : v) {
    printf("%d,", a);
  }
  printf("!\n");

  return 0;
}

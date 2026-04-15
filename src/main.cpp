#include <iostream>
#include "../include/alloc.h"

#define KB_1 100000

int main() {
  Alloc* alloc = new Alloc(KB_1);
  int* num = reinterpret_cast<int*>(alloc->allocate(sizeof(int)));
  *num = 4;
  std::cout << *num;
  delete alloc;
}
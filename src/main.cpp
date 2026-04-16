#include <cassert>
#include <cstdint>
#include <iostream>
#include "../include/alloc.h"

int main() {
  Alloc* alloc = new Alloc(1024);

  int* a = reinterpret_cast<int*>(alloc->allocate(sizeof(int)));
  double* b = reinterpret_cast<double*>(alloc->allocate(sizeof(double)));
  
  *a = 42;
  *b = 3.14;

  assert(*a == 42);
  assert(*b == 3.14);
  assert(reinterpret_cast<uintptr_t>(b) % alignof(double) == 0);
  assert(reinterpret_cast<char*>(b) >= reinterpret_cast<char*>(a) + sizeof(int));

  try {
    alloc->allocate(2048);
    assert(false && "should have thrown");
  } catch (const std::bad_alloc&) {}

  std::cout << "all tests passed\n";

  delete alloc;
}
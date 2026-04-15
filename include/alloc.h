#ifndef ALLOC_H
#define ALLOC_H

#include <cstddef>

class Alloc{
  public:
    Alloc(
      std::size_t _size
    );

    void* allocate(
      std::size_t _size,
      std::size_t alignment = alignof(std::max_align_t)
    );

    ~Alloc();

  private:
    void* base;
    void* current;
    void* end;
    std::size_t originalSize;
};

#endif
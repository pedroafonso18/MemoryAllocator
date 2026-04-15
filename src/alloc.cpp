#include "../include/alloc.h"
#include <cstddef>
#include <cstdint>
#include <new>
#include <unistd.h>
#include <sys/mman.h>

Alloc::Alloc(
  std::size_t _size
) 
{
  originalSize = _size;
  base = mmap(nullptr, _size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  if (base == MAP_FAILED)
  {
    throw std::bad_alloc();
  }

  current = base;
  end = reinterpret_cast<char*>(base) + _size;
}

Alloc::~Alloc()
{
  munmap(base, originalSize);
}

void* Alloc::allocate(
  std::size_t _size,
  std::size_t alignment
)
{
  uintptr_t raw = reinterpret_cast<uintptr_t>(current);
  uintptr_t aligned = (raw + alignment - 1) & ~(alignment - 1);

  if (aligned + _size >= reinterpret_cast<uintptr_t>(end))
  {
    throw std::bad_alloc();
  }

  current = reinterpret_cast<void*>(aligned + _size);

  return reinterpret_cast<void*>(aligned);
}
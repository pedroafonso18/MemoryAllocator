cmake_minimum_required(VERSION 3.31)
project(
  MemoryAllocator
  VERSION 1.0
  LANGUAGES CXX
)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(MemoryAllocator ${SOURCES} ${HEADERS})
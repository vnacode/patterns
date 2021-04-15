cmake_minimum_required(VERSION 3.5)

project(patterns LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(patterns
  main.cpp flyweight.hpp abstractFactory.h builder.h facade.h chain_of_responsobility.h
  template_method.h observer.h
)


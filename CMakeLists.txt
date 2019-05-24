cmake_minimum_required(VERSION 3.14)
project(Virtual_Machine_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Virtual_Machine_C main.c print.c execute.c VM.h input_to_array.c)
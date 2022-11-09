cmake_minimum_required(VERSION 3.21)
project(projet_DICO C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_DICO main.c word.c word.h list_cell.c list_cell.h)

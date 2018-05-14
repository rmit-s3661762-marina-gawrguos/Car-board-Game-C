cmake_minimum_required(VERSION 3.9)
project(CarboardGame_A1 C)

set(CMAKE_C_STANDARD 99)

add_executable(CarboardGame_A1 carboard.c board.c game.c helpers.c player.c)
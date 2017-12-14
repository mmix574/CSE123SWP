cmake_minimum_required(VERSION 3.9)
project(CSE123SWP)

set(CMAKE_CXX_STANDARD 11)

add_executable(CSE123SWP
        other/crc8.cpp
        common.h
        communicate.c
        communicate.h
        input.c
        input.h
        main.c
        receiver.c
        receiver.h
        sender.c
        sender.h
        util.c
        util.h)

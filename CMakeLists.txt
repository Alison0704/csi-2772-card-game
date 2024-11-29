cmake_minimum_required(VERSION 3.29)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code
        Card1.cpp
        Card1.h
        CardFactory.cpp
        Deck.h
        Deck.cpp
        Card.cpp
        main.cpp)

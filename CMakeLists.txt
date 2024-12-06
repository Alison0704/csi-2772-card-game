cmake_minimum_required(VERSION 3.29)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code
        CardFactory.cpp
        Deck.h
        Deck.cpp
        main.cpp
        CardFactory.h
        Chain.cpp
        DiscardPile.cpp
        TradeArea.cpp
        Hand.cpp
        Player.cpp
        Table.cpp)

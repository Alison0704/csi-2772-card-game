cmake_minimum_required(VERSION 3.29)
project(Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Code
        CardFactory.cpp
        CardFactory.h
        Chain.cpp
        Chain.h
        Deck.h
        Deck.cpp
        DiscardPile.cpp
        DiscardPile.h
        main.cpp
        Main.h
        TradeArea.cpp
        TradeArea.h
        Hand.cpp
        Hand.h
        Player.cpp
        Player.h
        Table.cpp
        Table.h
        Card.cpp
        Card.h)

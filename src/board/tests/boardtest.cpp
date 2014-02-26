#include "catch.hpp"
#include "board.h"

TEST_CASE("Board reports row winners"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(2, "x");
    board.Move(3, "x");
    REQUIRE("x" == board.winner());
}

TEST_CASE("Board reports column winners"){
    Board board = *new Board(2);
    board.Move(1, "o");
    board.Move(3, "o");
    REQUIRE("o" == board.winner());
}

TEST_CASE("Board reports diagonal winners"){
    Board board = *new Board(2);
    board.Move(1, "o");
    board.Move(4, "o");
    REQUIRE("o" == board.winner());
}

TEST_CASE("Board returns NO WINNER for no winner"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(3, "x");
    REQUIRE("NO WINNER" == board.winner());
}

TEST_CASE("Board returns true for full board"){
    Board board = *new Board(2);
    board.Move(1, "x");
    board.Move(2, "o");
    board.Move(3, "x");
    board.Move(4, "o");
    REQUIRE(true == board.Full());
}

TEST_CASE("Board returns false for non-full board"){
    Board board = *new Board(2);
    REQUIRE(false == board.Full());
}
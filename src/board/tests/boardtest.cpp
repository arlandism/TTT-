#include "catch.hpp"
#include "board.h"

TEST_CASE("Board::Full returns true for full board"){
    Board board = *new Board(2);
    board.Move(1, "x");
    board.Move(2, "o");
    board.Move(3, "x");
    board.Move(4, "o");
    REQUIRE(true == board.Full());
}

TEST_CASE("Board::Full returns false for non-full board"){
    Board board = *new Board(2);
    REQUIRE(false == board.Full());
}
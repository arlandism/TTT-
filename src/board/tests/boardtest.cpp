#include "catch.hpp"
#include "board.h"

TEST_CASE("Board::winner reports row winners"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(2, "x");
    board.Move(3, "x");
    REQUIRE("x" == board.winner());
}

TEST_CASE("Board::winner reports column winners"){
    Board board = *new Board(2);
    board.Move(1, "o");
    board.Move(3, "o");
    REQUIRE("o" == board.winner());
}

TEST_CASE("Board::winner reports diagonal winners"){
    Board board = *new Board(2);
    board.Move(1, "o");
    board.Move(4, "o");
    REQUIRE("o" == board.winner());
}

TEST_CASE("Board::winner returns NO WINNER for no winner"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(3, "x");
    REQUIRE("NO WINNER" == board.winner());
}

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

TEST_CASE("Board::Over returns true if the board is full"){
    Board board = *new Board(2);
    board.Move(1, "x");
    board.Move(2, "o");
    board.Move(3, "a");
    board.Move(4, "c");
    REQUIRE(true == board.Over());
}

TEST_CASE("Board::Over returns true if there's a winner on the board"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(2, "x");
    board.Move(3, "x");
    REQUIRE(true == board.Over());
}

TEST_CASE("Board::Over returns false if the board isn't empty and there's no winner"){
    Board board = *new Board(3);
    REQUIRE(false == board.Over());
}
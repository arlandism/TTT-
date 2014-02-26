#include "catch.hpp"
#include "board.h"

TEST_CASE("Board constructor allows default states"){
    std::vector<std::string> state_to_initialize = {"x", "o", "x", "", "", "", "", "", ""};
    std::vector<std::string> expected_state = {"x", "o", "x", "", "", "", "", "", ""};
    Board board = *new Board(state_to_initialize);
    REQUIRE(expected_state == board.state());
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

TEST_CASE("Board::state returns state of the board"){
    Board board = *new Board(2);
    std::vector<std::string> expected_state = {"", "", "", ""};
    REQUIRE(expected_state == board.state());
}

TEST_CASE("Board::OpenSpaces returns the open spaces on the board"){
    Board board = *new Board(2);
    std::vector<int> open_spaces = {1, 2, 3, 4};
    REQUIRE(open_spaces == board.OpenSpaces());
}

TEST_CASE("Board::Undo undos a move"){
    Board board = *new Board(2);
    board.Move(1, "x");
    board.Undo(1);
    std::vector<std::string> expected_state = {"", "", "", ""};
    REQUIRE(expected_state == board.state());
}
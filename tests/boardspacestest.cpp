#include "catch.hpp"
#include "boardspaces.h"
#include "vector"

TEST_CASE("BoardSpaces generates rows of a board"){
    std::vector<std::string> state = {"x", "", "", "", "", "", "o", "", ""};
    BoardSpaces board_spaces = *new BoardSpaces(state);
    std::vector<std::vector<std::string>> rows = board_spaces.Rows();
    std::vector<std::string> expectedFirstRow = {"x", "", ""};
    std::vector<std::string> expectedSecondRow = {"o", "", ""};
    REQUIRE(expectedFirstRow == rows.front());
    REQUIRE(expectedSecondRow == rows.back());
}

TEST_CASE("BoardSpaces generates columns of a board"){
    std::vector<std::string> state = {"o", "", "", "", "", "x", "", "", ""};
    BoardSpaces board_spaces = *new BoardSpaces(state);
    std::vector<std::vector<std::string>> columns = board_spaces.Columns();
    std::vector<std::string> expected_first_column = {"o", "", ""};
    std::vector<std::string> expected_second_column = {"", "x", ""};
    REQUIRE(expected_first_column == columns.front());
    REQUIRE(expected_second_column == columns.back());
}

TEST_CASE("BoardSpaces generates diagonals of a board"){
    std::vector<std::string> state = {"o", "x", "", ""};
    BoardSpaces board_spaces = *new BoardSpaces(state);
    std::vector<std::vector<std::string>> diagonals = board_spaces.Diagonals();
    std::vector<std::string> expected_diagonal_one = {"o", ""};
    std::vector<std::string> expected_diagonal_two = {"x", ""};
    REQUIRE(expected_diagonal_one == diagonals.front());
    REQUIRE(expected_diagonal_two == diagonals.back());
}
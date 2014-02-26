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
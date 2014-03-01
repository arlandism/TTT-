#include "catch.hpp"
#include "board.h"
#include "boardpresenter.h"

TEST_CASE("BoardPresenter::Present generates board string"){
    std::vector<std::string> board_state = {"x", "o", "x", "", "", "", "", "", ""};
    Board board = *new Board(board_state);
    std::string expected_format =
    "  x|  o|  x\n"
    "------------\n"
    "    |   |  \n"
    "------------\n"
    "    |   |  \n";
//    REQUIRE(expected_format == BoardPresenter::Present(board));
}
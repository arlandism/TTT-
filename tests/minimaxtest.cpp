#include "catch.hpp"
#include "minimax.h"
#include "vector"

TEST_CASE("Minimax chooses the winning move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    Minimax minimax = *new Minimax("o");
    int winningMove = 3;
    REQUIRE(winningMove == minimax.NextMove(board));
}
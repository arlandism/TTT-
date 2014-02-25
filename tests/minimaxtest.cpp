#include "catch.hpp"
#include "minimaxstrategy.h"
#include "vector"

TEST_CASE("MinimaxStrategy chooses the winning move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.setToken("o");
    int winningMove = 2;
    REQUIRE(winningMove == minimax.NextMove(board));
}

TEST_CASE("Minimax blocks a move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.setToken("x");
    int winningMove = 2;
    REQUIRE(winningMove == minimax.NextMove(board));
}
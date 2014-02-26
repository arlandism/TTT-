#include "catch.hpp"
#include "minimaxstrategy.h"
#include "vector"

TEST_CASE("MinimaxStrategy chooses the winning move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.set_token("o");
    int winning_move = 2;
    REQUIRE(winning_move == minimax.NextMove(board));
}

TEST_CASE("Minimax blocks a move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.set_token("x");
    int blocking_move = 2;
    REQUIRE(blocking_move == minimax.NextMove(board));
}
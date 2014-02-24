#include "catch.hpp"
#include "minimax.h"
#include "vector"

TEST_CASE("Minimax chooses the winning move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    Minimax minimax = *new Minimax("o");
    int winningMove = 2;
    REQUIRE(winningMove == minimax.NextMove(board));
}

TEST_CASE("Minimax blocks a move", "[minimax]"){
    std::vector<int> board = {"o", "o"};
    Minimax minimax = *new Minimax("x");
    int winningMove = 2;
    REQUIRE(winningMove == minimax.NextMove(board));
}
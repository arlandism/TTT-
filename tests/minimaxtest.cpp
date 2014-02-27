#include "catch.hpp"
#include "board.h"
#include "minimaxstrategy.h"
#include "vector"

TEST_CASE("MinimaxStrategy chooses the winning move"){
    Board board = *new Board(3);
    board.Move(1, "o");
    board.Move(2, "o");
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.set_token("o");
    int winning_move = 3;
    REQUIRE(winning_move == minimax.NextMove(board));
}

TEST_CASE("Minimax blocks a move", "[minimax]"){
    Board board = *new Board(3);
    board.Move(1, "o");
    board.Move(2, "o");
    MinimaxStrategy minimax = *new MinimaxStrategy();
    minimax.set_token("x");
    int blocking_move = 3;
    REQUIRE(blocking_move == minimax.NextMove(board));
}
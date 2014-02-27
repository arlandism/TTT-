#include "catch.hpp"
#include "board.h"
#include "minimaxstrategy.h"
#include "tttsettings.h"

TEST_CASE("MinimaxStrategy..."){

    TTTSettings *settings = new TTTSettings("x", "o");
    MinimaxStrategy minimax = *new MinimaxStrategy(settings);

    SECTION("chooses the winning move"){
        Board board = *new Board(3);
        board.Move(1, "o");
        board.Move(2, "o");
        minimax.set_token("o");
        int winning_move = 3;
        REQUIRE(winning_move == minimax.NextMove(board));
    }

    SECTION("blocks a move"){
        Board board = *new Board(3);
        board.Move(1, "o");
        board.Move(2, "o");
        minimax.set_token("x");
        int blocking_move = 3;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
}
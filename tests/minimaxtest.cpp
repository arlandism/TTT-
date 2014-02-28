#include "catch.hpp"
#include "board.h"
#include "minimax.h"
#include "tttsettings.h"

TEST_CASE("Minimax..."){

    TTTSettings *settings = new TTTSettings("x", "o");
    Minimax minimax = *new Minimax("x", settings);

    SECTION("chooses the winning move"){
        Board board = *new Board(3);
        board.Move(1, "x");
        board.Move(2, "x");
        int winning_move = 3;
        REQUIRE(winning_move == minimax.NextMove(board));
    }

    SECTION("blocks a move"){
        Board board = *new Board(3);
        board.Move(1, "o");
        board.Move(2, "o");
        int blocking_move = 3;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
}
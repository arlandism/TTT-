#include "catch.hpp"
#include "board.h"
#include "minimax.h"
#include "tttsettings.h"

TEST_CASE("Minimax..."){

    TTTSettings *settings = new TTTSettings("x", "o");
    Minimax minimax = *new Minimax(settings);

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
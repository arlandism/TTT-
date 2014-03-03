#include "catch.hpp"
#include "board.h"
#include "minimax.h"
#include "tttsettings.h"

TEST_CASE("Minimax::NextMove..."){

    TTTSettings *settings = new TTTSettings();
    settings->token_one = "x";
    settings->token_one = "o";
    Minimax minimax = *new Minimax("x", settings);

    SECTION("chooses the winning move"){
        Board board = *new Board(3);
        board.Move(3, "x");
        board.Move(6, "x");
        int winning_move = 9;
        REQUIRE(winning_move == minimax.NextMove(board));
    }

    SECTION("blocks a move"){
        Board board = *new Board(3);
        board.Move(1, "o");
        board.Move(4, "o");
        int blocking_move = 7;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
    
    SECTION("anticipates a fork"){
        Board board = *new Board(3);
        board.Move(1, "o");
        board.Move(2, "x");
        board.Move(3, "o");
        int blocking_move = 5;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
}
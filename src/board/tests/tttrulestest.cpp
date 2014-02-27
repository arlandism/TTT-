#include "catch.hpp"
#include "board.h"
#include "tttrules.h"
#include "vector"

std::string token_one = "x";
std::string token_two = "o";

TEST_CASE("TTTRules::Winner reports..."){
    
  SECTION("rowGameWinners"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE("x" == rules.GameWinner());
   }

   SECTION("columnGameWinners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "o");
        board->Move(3, "o");
        REQUIRE("o" == rules.GameWinner());
   }

   SECTION("diagonalGameWinners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "o");
        board->Move(4, "o");
        REQUIRE("o" == rules.GameWinner());
   }
    
    SECTION("No Winner for winner"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        REQUIRE("NO WINNER" == rules.GameWinner());
    }
}

TEST_CASE("TTTRules::GameOver returns..."){
    
    SECTION("true if the board is full"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "o");
        board->Move(3, "a");
        board->Move(4, "c");
        REQUIRE(true == rules.GameOver());
    }

    SECTION("true if there's aGameWinner on the board"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE(true == rules.GameOver());
    }

    SECTION("false if the board isn't empty and there's noGameWinner"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        REQUIRE(false == rules.GameOver());
    }
}

TEST_CASE("TTTRules::OtherToken returns the opposite token"){
    Board *board = new Board(3);
    TTTRules rules = *new TTTRules(board, "A", "B");
    REQUIRE("A" == rules.OtherToken("B"));
    REQUIRE("B" == rules.OtherToken("A"));
}
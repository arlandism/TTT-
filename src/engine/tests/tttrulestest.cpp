#include "catch.hpp"
#include "board.h"
#include "tttrules.h"
#include "vector"

std::string token_one = "x";
std::string token_two = "o";

TEST_CASE("TTTRules::Winner reports..."){
    
  SECTION("rowGameWinners"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE("x" == rules.GameWinner());
   }

   SECTION("columnGameWinners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "o");
        board->Move(3, "o");
        REQUIRE("o" == rules.GameWinner());
   }

   SECTION("diagonalGameWinners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "o");
        board->Move(4, "o");
        REQUIRE("o" == rules.GameWinner());
   }
    
    SECTION("empty string for no winner"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board);
        REQUIRE("" == rules.GameWinner());
    }
}

TEST_CASE("TTTRules::GameOver returns..."){
    
    SECTION("true if the board is full"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "x");
        board->Move(2, "o");
        board->Move(3, "a");
        board->Move(4, "c");
        REQUIRE(true == rules.GameOver());
    }

    SECTION("true if there's a winner on the board"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE(true == rules.GameOver());
    }

    SECTION("false if the board is empty"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board);
        REQUIRE(false == rules.GameOver());
    }
    
    SECTION("false if the board isn't empty, but there's no winner"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board);
        board->Move(1, "x");
        REQUIRE(false == rules.GameOver());
    }
}

TEST_CASE("TTTRules::OtherToken returns"){
    
    SECTION("x when given o"){
        REQUIRE("o" == TTTRules::OtherToken("x"));
    }
    
    SECTION("o when given x"){
        REQUIRE("x" == TTTRules::OtherToken("o"));
    }
}
#include "catch.hpp"
#include "board.h"
#include "tttrules.h"
#include "vector"

std::string token_one = "x";
std::string token_two = "o";

TEST_CASE("TTTRules::Winner reports..."){
    
  SECTION("row winners"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE("x" == rules.Winner());
   }

   SECTION("column winners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "o");
        board->Move(3, "o");
        REQUIRE("o" == rules.Winner());
   }

   SECTION("diagonal winners"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "o");
        board->Move(4, "o");
        REQUIRE("o" == rules.Winner());
   }
    
    SECTION("NO WINNER for no winner"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        REQUIRE("NO WINNER" == rules.Winner());
    }
}

TEST_CASE("TTTRules::Over returns... true if the board is full"){
    
    SECTION("true if the board is full"){
        Board *board = new Board(2);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "o");
        board->Move(3, "a");
        board->Move(4, "c");
        REQUIRE(true == rules.Over());
    }

    SECTION("true if there's a winner on the board"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        board->Move(1, "x");
        board->Move(2, "x");
        board->Move(3, "x");
        REQUIRE(true == rules.Over());
    }

    SECTION("false if the board isn't empty and there's no winner"){
        Board *board = new Board(3);
        TTTRules rules = *new TTTRules(board, token_one, token_two);
        REQUIRE(false == rules.Over());
    }
}

TEST_CASE("TTTRules::OtherToken returns the opposite token"){
    Board *board = new Board(3);
    TTTRules rules = *new TTTRules(board, "A", "B");
    REQUIRE("A" == rules.OtherToken("B"));
    REQUIRE("B" == rules.OtherToken("A"));
}
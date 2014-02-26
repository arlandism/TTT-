#include "catch.hpp"
#include "board.h"
#include "tttrules.h"
#include "vector"

TEST_CASE("TTTRules::Winner reports..."){
    
  std::string token_one = "x";
  std::string token_two = "o";
    
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
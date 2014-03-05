#include "catch.hpp"
#include "board.h"
#include "minimax.h"

TEST_CASE("Minimax::NextMove..."){

    Minimax minimax = *new Minimax("x");

    SECTION("goes for immediate win"){
        std::vector<std::string> board_state = {"x", "x", "",
                                                "", "o", "o",
                                                "", "", ""};
        Board board = *new Board(board_state);
        int winning_move = 3;
        REQUIRE(winning_move == minimax.NextMove(board));
    }
    
    SECTION("anticipates a fork"){
        std::vector<std::string> board_state = {"o", "x", "o",
                                                "", "", "",
                                                "", "", ""};
        Board board = *new Board(board_state);
        int blocking_move = 5;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
    
    SECTION("stops a win"){
        std::vector<std::string> board_state = {"x", "", "o",
                                                "x", "x", "",
                                                "o", "", ""};
        Board board = *new Board(board_state);
        int blocking_move = 6;
        REQUIRE(blocking_move == minimax.NextMove(board));
    }
}
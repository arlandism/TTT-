#include "catch.hpp"
#include "board.h"
#include "game.h"
#include "mockplayer.h"

TEST_CASE("Game::Round calls Move on..."){
    
    std::vector<int> player_one_moves = {1};
    std::vector<int> player_two_moves = {2};
    IPlayer *player_one = new MockPlayer("x", player_one_moves);
    IPlayer *player_two = new MockPlayer("o", player_two_moves);
    Board *board = new Board(3);
    
    SECTION("player one with board"){
        Game game = *new Game(board, player_one, player_two);
        game.Round();
        REQUIRE("x" == board->state()[0]);
    }
    
    SECTION("player two with board"){
        Game game = *new Game(board, player_one, player_two);
        game.Round();
        REQUIRE("o" == board->state()[1]);
    }
}
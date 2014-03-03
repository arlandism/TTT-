#include "catch.hpp"
#include "board.h"
#include "game.h"
#include "mockplayer.h"

TEST_CASE("Game::Round"){
    
    std::vector<int> player_one_moves = {1};
    std::vector<int> player_two_moves = {2};
    MockPlayer mock_player_one = *new MockPlayer("x", player_one_moves);
    MockPlayer mock_player_two = *new MockPlayer("o", player_two_moves);
    IPlayer *player_one = &mock_player_one;
    IPlayer *player_two = &mock_player_two;
    Board *board = new Board(3);
    
    SECTION("calls Move on player one with board"){
        Game game = *new Game(board, player_one, player_two);
        game.Round();
        REQUIRE("x" == board->state()[0]);
    }
    
    SECTION("calls Move on player two with board"){
        Game game = *new Game(board, player_one, player_two);
        game.Round();
        REQUIRE("o" == board->state()[1]);
    }
    
    SECTION("calls Move on player two with most up-to-date board"){
        Board board = *new Board(2);
        Game game = *new Game(&board, player_one, player_two);
        game.Round();
        std::vector<std::string> expected_state = {"x", "", "", ""};
        std::vector<std::string> state_received_by_player_two = mock_player_two.LastRecordedState();
        REQUIRE(expected_state == state_received_by_player_two);
    }
    
    SECTION("doesn't pass board to players if game is over"){
        std::vector<std::string> board_state = {"x", "x", "x", "", "", "", "", "", ""};
        Board board = *new Board(board_state);
        Game game = *new Game(&board, player_one, player_two);
        game.Round();
        REQUIRE(false == mock_player_one.move_called());
        REQUIRE(false == mock_player_two.move_called());
    }
}

TEST_CASE("Game::Summary displays board"){
    std::vector<int> player_one_moves = {};
    std::vector<int> player_two_moves = {};
    IPlayer *player_one = new MockPlayer("x", player_one_moves);
    IPlayer *player_two = new MockPlayer("o", player_two_moves);
    std::vector<std::string> board_state = {"x", "o", "x", "", "", "", "", "", ""};
    Board *board = new Board(board_state);
    Game game = Game(board, player_one, player_two);
    
    std::string expected_format =
    "  x|  o|  x\n"
    "------------\n"
    "    |   |   \n"
    "------------\n"
    "    |   |   \n";
    REQUIRE(expected_format == game.Summary());
}
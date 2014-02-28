#include "game.h"

void Game::Round(){
    int player_one_move = player_one_->Move(*board_);
    int player_two_move = player_two_->Move(*board_);
    board_->Move(player_one_move, player_one_->token());
    board_->Move(player_two_move, player_two_->token());
}
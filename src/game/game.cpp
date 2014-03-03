#include "game.h"

void Game::Round(){
    int player_one_move = player_one_->Move(*board_);
    board_->Move(player_one_move, player_one_->token());
    
    int player_two_move = player_two_->Move(*board_);
    board_->Move(player_two_move, player_two_->token());
}

std::string Game::Summary(){
    return BoardPresenter::Present(*board_);
}
#include "game.h"

void Game::Round(){
    PlayerMove(player_one_);
    PlayerMove(player_two_);
}

void Game::PlayerMove(IPlayer *player){
    TTTRules rules = *new TTTRules(board_);
    if (not rules.GameOver()){
        int player_move = player->Move(*board_);
        board_->Move(player_move, player->token());
    }
}

std::string Game::Summary(){
    return BoardPresenter::Present(*board_);
}
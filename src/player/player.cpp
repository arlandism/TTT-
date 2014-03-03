#include "player.h"

std::string Player::token (){
    return token_;
}

int Player::Move(Board board){
    int move = move_strategy_->NextMove(board);
    if (ValidMove(board, move)){
        return move;
    }
    return Move(board);
}

bool Player::ValidMove(Board board, int move){
    std::vector<int> valid_moves = board.OpenSpaces();
    return std::find(valid_moves.begin(), valid_moves.end(), move) != valid_moves.end();
}
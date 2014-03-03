#include "mockplayer.h"

int MockPlayer::Move(Board board){
    RecordBoard(board);
    move_called_ = true;
    
    int next_output_value = inputs_to_return_.back();
    inputs_to_return_.pop_back();
    return next_output_value;
}

std::string MockPlayer::token(){
    return token_;
}

bool MockPlayer::move_called(){
    return move_called_;
}

void MockPlayer::RecordBoard(Board board){
    std::vector<std::string> current_state = board.state();
    recorded_board_states_.push_back(current_state);
}

std::vector<std::string> MockPlayer::LastRecordedState(){
    return recorded_board_states_.back();
}
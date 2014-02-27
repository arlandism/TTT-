#include "minimaxstrategy.h"
#include "tttrules.h"

int MinimaxStrategy::NextMove(Board board){
    return HighestScoringMove(board, token_);
}

int MinimaxStrategy::HighestScoringMove(Board board, std::string current_token){
    Board *board_ptr = &board;
    TTTRules rules = *new TTTRules(board_ptr, "o", "x");
    if (rules.GameOver()){
        return EvaluateGame(rules.GameWinner());
    } else {
        std::vector<int> available_spaces = board.OpenSpaces();
        std::vector<int>::const_iterator iterator;
        if (current_token == token_){
            int best_score = -10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int space = *iterator;
                board.Move(space, current_token);
                Board new_board  = *new Board(board.state());
                board.Undo(space);
                int board_score = HighestScoringMove(new_board, rules.OpponentToken(current_token));
                int score = std::max(board_score, best_score);
                return score;
            }
        } else {
            int best_score = 10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int space = *iterator;
                board.Move(space, current_token);
                Board new_board  = *new Board(board.state());
                board.Undo(space);
                int board_score = HighestScoringMove(new_board, rules.OpponentToken(current_token));
                int score = std::min(board_score, best_score);
                return score;
           }
        }
    }
    return 2;
}

void MinimaxStrategy::set_token(std::string token){
    token_ = token;
}

int MinimaxStrategy::EvaluateGame(std::string winner){
    if (winner == token_){
        return 1;
    } else if (winner == "NO WINNER"){
        return 0;
    }
    return -1;
}
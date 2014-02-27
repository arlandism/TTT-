#include "minimaxstrategy.h"
#include "tttrules.h"

int MinimaxStrategy::NextMove(Board board){
    std::map<int, int> move_to_score;
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        int move_score = EvaluateMove(board, move, token_);
        move_to_score[move_score] = move;
    }
    int highest_score =  move_to_score.rbegin()->first;
    int highest_rated_move = move_to_score[highest_score];
    return highest_rated_move;
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

int MinimaxStrategy::EvaluateMove(Board board, int space, std::string token, bool maximizing){
    board.Move(space, token);
    Board *board_ptr = &board;
    TTTRules rules = *new TTTRules(board_ptr, "o", "x");
    if (rules.GameOver()){
        return EvaluateGame(rules.GameWinner());
    } else {
        std::vector<int> available_spaces = board.OpenSpaces();
        std::vector<int>::const_iterator iterator;
        if (maximizing){
            int highest_score = -10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                std::string next_token = rules.OpponentToken(token);
                Board next_board = *new Board(board.state());
                int score_for_move = EvaluateMove(next_board, next_space, next_token, -maximizing);
                int highest_score = std::max(highest_score, score_for_move);
            }
            return highest_score;
        } else {
            int highest_score = 10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                std::string next_token = rules.OpponentToken(token);
                Board next_board = *new Board(board.state());
                int score_for_move = EvaluateMove(next_board, next_space, next_token, -maximizing);
                int highest_score = std::min(highest_score, score_for_move);
            }
            return highest_score;
        }
    }
}

int MinimaxStrategy::MinMax(int score, std::string token){
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
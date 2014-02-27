#include "minimaxstrategy.h"
#include "tttrules.h"

int MinimaxStrategy::NextMove(Board board){
    std::multimap<int, int> move_to_score;
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        int move_score = EvaluateMove(board, move, token_);
        std::pair<int,int> move_score_pair = {move_score, move};
        move_to_score.insert(move_score_pair);
    }
    int highest_score =  move_to_score.rbegin()->first;
    int highest_rated_move = move_to_score.find(highest_score)->second;
    return highest_rated_move;
}

int MinimaxStrategy::EvaluateMove(Board board, int space, std::string token, bool maximizing){
    board.Move(space, token);
    Board *board_ptr = &board;
    TTTRules rules = *new TTTRules(board_ptr, "o", "x");
    std::string opponent_token = rules.OpponentToken(token);
    std::string game_winner = rules.GameWinner();
    if (rules.GameOver()){
        return EvaluateGame(game_winner, opponent_token);
    } else {
        std::vector<int> available_spaces = board.OpenSpaces();
        std::vector<int>::const_iterator iterator;
        std::string next_token = rules.OpponentToken(token);
        Board next_board = *new Board(board.state());
        if (maximizing){
            int highest_score = -10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                int score_for_move = EvaluateMove(next_board, next_space, next_token, -maximizing);
                int highest_score = std::max(highest_score, score_for_move);
            }
            return highest_score;
        } else {
            int highest_score = 10000;
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                int score_for_move = EvaluateMove(next_board, next_space, next_token, -maximizing);
                int highest_score = std::min(highest_score, score_for_move);
            }
            return highest_score;
        }
    }
}

void MinimaxStrategy::set_token(std::string token){
    token_ = token;
}

int MinimaxStrategy::EvaluateGame(std::string winner, std::string opponent_token){
    if (winner == token_){
        return 1;
    } else if (winner == opponent_token){
        return -1;
    }
    return 0;
}
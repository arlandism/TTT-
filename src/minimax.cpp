#include "minimax.h"

int Minimax::NextMove(Board board){
    std::multimap<int, int> move_to_score = EvaluateRemainingMoves(board);
    int highest_rated_move = HighestRatedMove(move_to_score);
    return highest_rated_move;
}

int Minimax::EvaluateMove(Board board, int space, std::string token, int alpha, int beta, bool maximizing){
    board.Move(space, token);
    Board *board_ptr = &board;
    TTTRules rules = *new TTTRules(board_ptr, "o", "x");
    std::string opponent_token = settings_->OtherToken(token);
    std::string game_winner = rules.GameWinner();
    if (rules.GameOver()){
        return EvaluateGame(game_winner, opponent_token);
    } else {
        std::vector<int> available_spaces = board.OpenSpaces();
        std::vector<int>::const_iterator iterator;
        std::string next_token = rules.OpponentToken(token);
        Board next_board = *new Board(board.state());
        if (maximizing){
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                int score_for_move = BestScoreOfChildren(board, token, next_space);
                int alpha = std::max(alpha, score_for_move);
                if (ShouldPrune(alpha, beta)){
                    break;
                }
            }
            return alpha;
        } else {
            for (iterator = available_spaces.begin(); iterator != available_spaces.end(); iterator++){
                int next_space = *iterator;
                int score_for_move = BestScoreOfChildren(board, token, next_space);
                int beta = std::min(beta, score_for_move);
                if (ShouldPrune(alpha, beta)){
                    break;
                }
            }
            return beta;
        }
    }
}

int Minimax::BestScoreOfChildren(Board board, std::string token, int space){
    std::vector<int> available_spaces = board.OpenSpaces();
    std::string next_token = settings_->OtherToken(token);
    int score_for_move = EvaluateMove(board, space, token);
    return score_for_move;
}

int Minimax::HighestRatedMove(std::multimap<int, int> scores_to_moves){
    int highest_score = scores_to_moves.rbegin()->first;
    int highest_rated_move = scores_to_moves.find(highest_score)->second;
    return highest_rated_move;
}

std::multimap<int, int> Minimax::EvaluateRemainingMoves(Board board){
    std::multimap<int, int> move_to_score;
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        int move_score = EvaluateMove(board, move, token_);
        std::pair<int,int> move_score_pair = {move_score, move};
        move_to_score.insert(move_score_pair);
    }
    return move_to_score;
}

bool Minimax::ShouldPrune(int alpha, int beta){
    return beta <= alpha;
}

void Minimax::set_token(std::string token){
    token_ = token;
}

int Minimax::EvaluateGame(std::string winner, std::string opponent_token){
    if (winner == token_){
        return 1;
    } else if (winner == opponent_token){
        return -1;
    }
    return 0;
}
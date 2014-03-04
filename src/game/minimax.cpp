#include "minimax.h"

int Minimax::NextMove(Board board){
    std::multimap<int, int> score_to_move_map = ScorePossibleMoves(board);
    int move = HighestRatedMove(score_to_move_map);
    return move;
}

int Minimax::HighestRatedMove(std::multimap<int, int> scores_to_moves){
    int highest_score = scores_to_moves.rbegin()->first;
    int highest_rated_move = scores_to_moves.find(highest_score)->second;
    return highest_rated_move;
}

std::multimap<int, int> Minimax::ScorePossibleMoves(Board board){
    std::multimap<int, int> score_to_move_map;
    std::vector<int> possible_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    for (iterator = possible_moves.begin(); iterator != possible_moves.end(); iterator++){
        int move = *iterator;
        int score = ScoreMove(board, move, token_);
        score_to_move_map.insert( std::pair<int, int>(score, move) );
    }
    return score_to_move_map;
}

int Minimax::ScoreMove(Board board, int move, std::string current_token, int depth){
    Board sandbox_board = *new Board( board.state() );
    sandbox_board.Move(move, current_token);
    TTTRules rules = *new TTTRules(&sandbox_board);
    if (rules.GameOver() or depth == 0){
        return EvaluateGame(rules.GameWinner(), current_token, depth);
    } else {
        std::string opponent_token = OtherToken(current_token);
        depth += 1;
        if (Maximizing(current_token)) {
            return Minimize(sandbox_board, opponent_token, depth);
        } else {
            return Maximize(sandbox_board, opponent_token, depth);
        }
    }
}

bool Minimax::Maximizing(std::string token){
    return token == token_;
}

int Minimax::Maximize(Board board, std::string token, int depth){
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    int best_score = -10000;
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        best_score = std::max(best_score, ScoreMove(board, move, token, depth));
    }
    return best_score;
}

int Minimax::Minimize(Board board, std::string token, int depth){
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    int best_score = 10000;
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        best_score = std::min(best_score, ScoreMove(board, move, token, depth));
    }
    return best_score;
}

int Minimax::EvaluateGame(std::string winner, std::string current_token, int depth){
    std::string opponent_token = OtherToken(token_);
    int score;
    if (winner == token_){
        score = 1;
    } else if (winner == opponent_token){
        score =  -1;
    } else {
        score = 0;
    }
    return score * MAX_DEPTH / depth;
}

std::string Minimax::OtherToken(std::string token){
    return TTTRules::OtherToken(token);
}
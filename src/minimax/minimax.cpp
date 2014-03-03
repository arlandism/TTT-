#include "minimax.h"

int Minimax::NextMove(Board board){
    std::multimap<int, int> score_to_move_map = ScorePossibleMoves(board);
    int move = HighestRatedMove(score_to_move_map);
    return move;
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

int Minimax::ScoreMove(Board board, int move, std::string current_token, int depth, bool maximizing){
    Board sandbox_board = *new Board( board.state() );
    sandbox_board.Move(move, current_token);
    if (GameOver(sandbox_board) or depth == 0){
        return EvaluateGame(GameWinner(sandbox_board), current_token);
    } else {
        std::string opponent_token = OtherToken(current_token);
        depth -= 1;
        if (maximizing) {
            return Maximize(sandbox_board, opponent_token, depth);
        } else {
            return Minimize(sandbox_board, opponent_token, depth);
        }
    }
}

bool Minimax::GameOver(Board board){
    TTTRules rules = *new TTTRules(&board);
    return rules.GameOver();
}

std::string Minimax::GameWinner(Board board){
    TTTRules rules = *new TTTRules(&board);
    return rules.GameWinner();
}

int Minimax::Maximize(Board board, std::string token, int depth){
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    int best_score = -10000;
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        best_score = std::min(best_score, ScoreMove(board, move, token, false, depth));
    }
    return best_score;
}

int Minimax::Minimize(Board board, std::string token, int depth){
    std::vector<int> available_moves = board.OpenSpaces();
    std::vector<int>::const_iterator iterator;
    int best_score = 10000;
    for (iterator = available_moves.begin(); iterator != available_moves.end(); iterator++){
        int move = *iterator;
        best_score = std::max(best_score, ScoreMove(board, move, token, true, depth));
    }
    return best_score;
}

int Minimax::EvaluateGame(std::string winner, std::string current_token){
    std::string opponent_token = OtherToken(current_token);
    if (winner == current_token){
        return 1;
    } else if (winner == opponent_token){
        return -1;
    }
    return 0;
}

int Minimax::HighestRatedMove(std::multimap<int, int> scores_to_moves){
   int highest_score = scores_to_moves.rbegin()->first;
   int highest_rated_move = scores_to_moves.find(highest_score)->second;
   return highest_rated_move;
}

std::string Minimax::OtherToken(std::string token){
    if (token == "x"){
        return "o";
    }
    return "x";
}
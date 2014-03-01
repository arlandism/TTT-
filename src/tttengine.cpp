#include "tttengine.h"

void TTTEngine::StartGame(std::string first_player_type, std::string first_player_token,
                                 std::string second_player_type, std::string second_player_token){
    Board *board = new Board(3);
    Player *player_one = CreatePlayer(first_player_type, first_player_token);
    Player *player_two = CreatePlayer(second_player_type, second_player_token);
    Game game = *new Game(board, player_one, player_two);
    TTTRules rules = *new TTTRules(board);
    while (not (rules.GameOver())){
        game.Round();
    }
    GamePresenter::PresentWinner(rules.GameWinner());
}

Player * TTTEngine::CreatePlayer(std::string player_type, std::string player_token){
    
    MoveStrategy *move_strategy;
    if (player_type == "human"){
        move_strategy = new TerminalInput();
    } else {
        move_strategy = new Minimax(player_token, new TTTSettings());
    }
    return new Player(player_token, move_strategy);
}

bool TTTEngine::AffirmativeAnswer(std::string answer){
    return answer == "y";
}

bool TTTEngine::ValidPlayerChoice(std::string choice){
    return std::find(valid_player_choices.begin(), valid_player_choices.end(), choice) != valid_player_choices.end();
}
#include <iostream>
#include "game.h"
#include "gamepresenter.h"
#include "inputvalidator.h"
#include "terminalinput.h"
#include "tttsettings.h"
#include "map"
#include "vector"
#include "tttengine.h"

std::string GetFromUser(std::vector<std::string> valid_choices, std::string prompt){
    std::string user_choice;
    while (not (InputValidator::IsValid(valid_choices, user_choice))){
        std::cout << prompt;
        std::cin >> user_choice;
    }
    return user_choice;
}

std::string GetPlayerType(TTTEngine engine){
    return GetFromUser(engine.valid_player_choices, GamePresenter::PlayerPrompt());
}

std::string GetToken(TTTEngine engine){
    return GetFromUser(engine.valid_token_choices, GamePresenter::TokenPrompt());
}

Player CreatePlayer(std::string type, std::string token){
    MoveStrategy *move_strategy;
    if (type == "human"){
        move_strategy = new TerminalInput();
    } else {
        move_strategy = new Minimax(token, new TTTSettings());
    }
    return *new Player(token, move_strategy);
}

void GameLoop(){
    std::string first_player_type, second_player_type,
                first_player_token, second_player_token,
                play_again_answer;
    
    TTTEngine engine = *new TTTEngine();
    std::cout << GamePresenter::WelcomeBanner();
    
    first_player_type = GetPlayerType(engine);
    first_player_token = GetToken(engine);
    
    second_player_type = GetPlayerType(engine);
    second_player_token = GetToken(engine);
    
    Player player_one = CreatePlayer(first_player_type, first_player_token);
    Player player_two = CreatePlayer(second_player_type, second_player_token);
    Board board = *new Board(3);
    Game game = *new Game(&board, &player_one, &player_two);
    TTTRules rules = *new TTTRules(&board);
    while (not rules.GameOver()){
        game.Round();
    }
//    engine.StartGame(first_player_type, first_player_token,
//                     second_player_type, second_player_token);
    std::cout << GamePresenter::ReplayPrompt();
    std::cin >> play_again_answer;
    if (engine.AffirmativeAnswer(play_again_answer)){
        GameLoop();
    }
}

int main(int argc, const char * argv[])
{
    GameLoop();
    return 0;
}
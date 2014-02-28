#include <iostream>
#include "gamepresenter.h"
#include "inputvalidator.h"
#include "tttconsoleengine.h"

std::string GetPlayerType(TTTConsoleEngine engine){
    std::vector<std::string> valid_player_choices = engine.valid_player_choices;
    std::string user_choice = "";
    while (not (InputValidator::IsValid(valid_player_choices, user_choice))){
        std::cout << "Please select a player type from\n" << GamePresenter::PresentChoices(valid_player_choices);
        std::cin >> user_choice;
    }
    return user_choice;
}

std::string GetToken(){
    std::string user_choice;
    std::cout << "Please select a token:\n";
    std::cin >> user_choice;
    return user_choice;
}

int main(int argc, const char * argv[])
{
    std::string first_player_type, second_player_type, first_player_token, second_player_token;
    TTTConsoleEngine engine = *new TTTConsoleEngine();
    GamePresenter::WelcomeBanner();
    
    GamePresenter::PlayerPrompt();
    first_player_type = GetPlayerType(engine);
    GamePresenter::TokenPrompt();
    first_player_token = GetToken();
    
    GamePresenter::PlayerPrompt();
    second_player_type = GetPlayerType(engine);
    GamePresenter::TokenPrompt();
    second_player_token = GetToken();
    
//    engine.StartGame(first_player_type, first_player_token,
//                     second_player_type, second_player_token);
    return 0;
}
#include <iostream>
#include "gamepresenter.h"
#include "inputvalidator.h"
#include "tttconsoleengine.h"

std::string GetPlayerType(TTTConsoleEngine engine){
    std::vector<std::string> valid_player_choices = engine.valid_player_choices;
    std::string user_choice = "";
    while (not (InputValidator::IsValid(valid_player_choices, user_choice))){
        std::cout << GamePresenter::PresentPlayerChoices(valid_player_choices);
        std::cin >> user_choice;
    }
    return user_choice;
}

std::string GetToken(){
    std::string user_choice;
    std::cout << GamePresenter::TokenPrompt();
    std::cin >> user_choice;
    return user_choice;
}

int main(int argc, const char * argv[])
{
    std::string first_player_type, second_player_type, first_player_token, second_player_token;
    TTTConsoleEngine engine = *new TTTConsoleEngine();
    std::cout << GamePresenter::WelcomeBanner();
    
    first_player_type = GetPlayerType(engine);
    first_player_token = GetToken();
    
    second_player_type = GetPlayerType(engine);
    second_player_token = GetToken();
    
//    engine.StartGame(first_player_type, first_player_token,
//                     second_player_type, second_player_token);
    std::cout << GamePresenter::ReplayPrompt();
    return 0;
}
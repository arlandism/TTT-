#include <iostream>
#include "gamepresenter.h"
#include "tttengine.h"

std::string GetPlayerType(TTTEngine engine){
    std::string user_choice;
    while (not (engine.ValidPlayerChoice(user_choice))){
        std::cout << GamePresenter::PresentPlayerChoices(engine.valid_player_choices);
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

void GameLoop(){
    std::string first_player_type, second_player_type,
                first_player_token, second_player_token,
                play_again_answer;
    
    TTTEngine engine = *new TTTEngine();
    std::cout << GamePresenter::WelcomeBanner();
    
    first_player_type = GetPlayerType(engine);
    first_player_token = GetToken();
    
    second_player_type = GetPlayerType(engine);
    second_player_token = GetToken();
    
    engine.StartGame(first_player_type, first_player_token,
                     second_player_type, second_player_token);
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
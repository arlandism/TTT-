#include "gamepresenter.h"

std::string GamePresenter::WelcomeBanner(){
    std::string banner =
    "***************************\n"
    "* Welcome to Tic Tac Toe! *\n"
    "***************************\n";
    return banner;
}

std::string GamePresenter::PlayerPrompt(){
    return "Please select a player type:\n";
}

std::string GamePresenter::TokenPrompt(){
    return "What's that player's token?\n";
}

std::string GamePresenter::PresentWinner(TTTRules rules){
    return "And the winner is... " + rules.GameWinner() + "\n";
}

std::string GamePresenter::ReplayPrompt(){
    return "Would you like to play again?\n";
}

std::string GamePresenter::PresentPlayerChoices(std::vector<std::string> choices){
    std::string presented = GamePresenter::PlayerPrompt();
    std::vector<std::string>::const_iterator iterator;
    for (iterator = choices.begin(); iterator != choices.end(); iterator++){
        std::string choice = *iterator;
        presented += (choice + "\n");
    }
    return presented;
}

bool GamePresenter::AffirmativeAnswer(std::string answer){
    return answer == "y";
}
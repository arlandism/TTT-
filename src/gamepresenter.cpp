#include "gamepresenter.h"

std::string GamePresenter::WelcomeBanner(){
    std::string banner =
    "***************************\n"
    "* Welcome to Tic Tac Toe! *\n"
    "***************************\n";
    return banner;
}

std::string GamePresenter::PlayerPrompt(){
    return "What type of player would you like to be?\n";
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

bool GamePresenter::AffirmativeAnswer(std::string answer){
    return answer == "y";
}
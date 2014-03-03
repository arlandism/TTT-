#include "gamepresenter.h"

std::string GamePresenter::WelcomeBanner(){
    std::string banner =
    "***************************\n"
    "* Welcome to Tic Tac Toe! *\n"
    "***************************\n";
    return banner;
}

std::string GamePresenter::PlayerPrompt(std::vector<std::string> choices){
    std::string formatted_player_choices = "";
    std::vector<std::string>::const_iterator iterator;
    for (iterator = choices.begin(); iterator != choices.end(); iterator++){
        std::string choice = *iterator;
        formatted_player_choices += (choice + "\n");
    }
    return "\nPlease select a player type:\n" + formatted_player_choices + "\n";
}

std::string GamePresenter::TokenPrompt(){
    return "\nWhat's that player's token?\n";
}

std::string GamePresenter::PresentWinner(std::string winner){
    if (winner != Board::EmptySpace){
        return "\nAnd the winner is... " + winner + "\n";
    }
    return "\nIt's a tie!\n";
}

std::string GamePresenter::ReplayPrompt(){
    return "\nWould you like to play again?\n";
}
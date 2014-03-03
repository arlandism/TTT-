#include "gamepresenter.h"

std::string GamePresenter::WelcomeBanner(){
    std::string banner =
    "***************************\n"
    "* Welcome to Tic Tac Toe! *\n"
    "***************************\n";
    return banner;
}

std::string GamePresenter::PlayerPrompt(std::vector<std::string> player_choices){
    std::string formatted_player_choices = GamePresenter::JoinChoices(player_choices);
    return "\nPlease select a player type:\n" + formatted_player_choices + "\n";
}

std::string GamePresenter::TokenPrompt(std::vector<std::string> token_choices){
    std::string formatted_token_choices = GamePresenter::JoinChoices(token_choices);
    return "\nPlease select a token:\n" + formatted_token_choices + "\n";
}

std::string GamePresenter::JoinChoices(std::vector<std::string> choices){
    std::string formatted_choices = "";
    std::vector<std::string>::const_iterator iterator;
    for (iterator = choices.begin(); iterator != choices.end(); iterator++){
        std::string choice = *iterator;
        formatted_choices += (choice + "\n");
    }
    return formatted_choices;
}

std::string GamePresenter::PresentWinner(std::string winner){
    if (winner != Board::EmptySpace){
        return "\nAnd the winner is... " + winner + "\n";
    }
    return "\nIt's a tie!\n";
}
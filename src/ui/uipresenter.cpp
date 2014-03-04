#include "uipresenter.h"

std::string UIPresenter::WelcomeBanner(){
    std::string banner =
    "***************************\n"
    "* Welcome to Tic Tac Toe! *\n"
    "***************************\n";
    return banner;
}

std::string UIPresenter::PlayerPrompt(std::string order, std::vector<std::string> player_choices){
    std::string formatted_player_choices = UIPresenter::JoinChoices(player_choices);
    return "\nPlease select a type for the " + order + " player. Options are: \n" + formatted_player_choices + "\n";
}

std::string UIPresenter::TokenPrompt(std::vector<std::string> token_choices){
    std::string formatted_token_choices = UIPresenter::JoinChoices(token_choices);
    return "\nPlease select a token. Options are: \n" + formatted_token_choices + "\n";
}

std::string UIPresenter::JoinChoices(std::vector<std::string> choices){
    std::string formatted_choices = "";
    std::vector<std::string>::const_iterator iterator;
    for (iterator = choices.begin(); iterator != choices.end(); iterator++){
        std::string choice = *iterator;
        formatted_choices += (choice + "\n");
    }
    return formatted_choices;
}

std::string UIPresenter::PresentWinner(std::string winner){
    if (winner != Board::EmptySpace){
        return "\nAnd the winner is... " + winner + "\n";
    }
    return "\nIt's a tie!\n";
}
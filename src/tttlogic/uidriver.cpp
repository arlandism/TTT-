#include "uidriver.h"

std::string UIDriver::GetPlayerType(std::string order, std::vector<std::string> valid_player_choices){
    std::string prompt = UIPresenter::PlayerPrompt(order, valid_player_choices);
    return GetFromUser(valid_player_choices, prompt);
}

std::string UIDriver::GetToken(std::vector<std::string> valid_token_choices){
    std::string prompt = UIPresenter::TokenPrompt(valid_token_choices);
    std::string token = GetFromUser(valid_token_choices, UIPresenter::TokenPrompt(valid_token_choices));
    used_token_ = token;
    return token;
}

std::string UIDriver::GetFromUser(std::vector<std::string> valid_choices, std::string prompt){
    std::string user_choice;
    while (not (InputValidator::IsValid(valid_choices, user_choice))){
        io_->Print(prompt);
        user_choice = io_->GetInput();
    }
    return user_choice;
}

void UIDriver::Display(std::string message){
    io_->Print(message);
}

void UIDriver::DisplayWelcome(){
    io_->Print(UIPresenter::WelcomeBanner());
}

void UIDriver::DisplayBoard(Board board){
    io_->Print("\n" + BoardPresenter::Present(board));
}

void UIDriver::DisplayWinner(std::string winner){
    io_->Print(UIPresenter::PresentWinner(winner));
}
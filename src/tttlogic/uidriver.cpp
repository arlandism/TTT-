#include "uidriver.h"

IPlayer * UIDriver::CreatePlayer(std::string player_type, std::string player_token){
    return factory_->Create(player_type, player_token);
}

std::string UIDriver::GetPlayerType(std::vector<std::string> valid_player_choices){
    std::string prompt = GamePresenter::PlayerPrompt(valid_player_choices);
    return GetFromUser(valid_player_choices, prompt);
}

std::string UIDriver::GetToken(std::vector<std::string> valid_token_choices){
    std::string prompt = GamePresenter::TokenPrompt(valid_token_choices);
    std::string token = GetFromUser(valid_token_choices, GamePresenter::TokenPrompt(valid_token_choices));
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
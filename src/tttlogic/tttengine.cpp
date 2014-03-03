#include "tttengine.h"
#include "consolemovestrategy.h"

void TTTEngine::StartGame(){
    std::string first_player_type, second_player_type,
                first_player_token, second_player_token,
                play_again_answer;
    
    io_->Print(GamePresenter::WelcomeBanner());
    
    first_player_type = GetPlayerType();
    first_player_token = GetToken();
    
    second_player_type = GetPlayerType();
    second_player_token = GetToken();
    
    IPlayer *player_one = CreatePlayer(first_player_type, first_player_token);
    IPlayer *player_two = CreatePlayer(second_player_type, second_player_token);
    Board board = *new Board(3);
    Game game = *new Game(&board, player_one, player_two);
    TTTRules rules = *new TTTRules(&board);
    while (not rules.GameOver()){
        game.Round();
    }
    GamePresenter::PresentWinner(rules.GameWinner());
    io_->Print(GamePresenter::ReplayPrompt());
    std::cin >> play_again_answer;
}

IPlayer * TTTEngine::CreatePlayer(std::string player_type, std::string player_token){
    return factory_->Create(player_type, player_token);
}

std::string TTTEngine::GetPlayerType(){
    return GetFromUser(valid_player_choices, GamePresenter::PlayerPrompt());
}

std::string TTTEngine::GetToken(){
    return GetFromUser(valid_token_choices, GamePresenter::TokenPrompt());
}

std::string TTTEngine::GetFromUser(std::vector<std::string> valid_choices, std::string prompt){
    std::string user_choice;
    while (not (InputValidator::IsValid(valid_choices, user_choice))){
        io_->Print(prompt);
        user_choice = io_->GetInput();
    }
    return user_choice;
}
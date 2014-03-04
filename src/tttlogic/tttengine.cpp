#include "tttengine.h"

void TTTEngine::RunGame(){
    
    driver_->DisplayWelcome();
    IPlayer *player_one = CreatePlayerOne();
    std::string first_player_token = player_one->token();
    
    IPlayer *player_two = CreatePlayerTwo(first_player_token);
    
    Board board = *new Board(3);
    Game game = *new Game(&board, player_one, player_two);
    TTTRules rules = *new TTTRules(&board);
    while (not rules.GameOver()){
        game.Round();
    }
    driver_->DisplayBoard(board);
    driver_->DisplayWinner(rules.GameWinner());
}

IPlayer * TTTEngine::CreatePlayerOne(){
    std::string player_type = driver_->GetPlayerType("first", factory_->ValidPlayerChoices());
    std::string player_token = driver_->GetToken(TTTRules::ValidTokenChoices());
    IPlayer *player_one = CreatePlayer(player_type, player_token);
    return player_one;
}

IPlayer * TTTEngine::CreatePlayerTwo(std::string first_player_token){
    std::string player_type = driver_->GetPlayerType("second", factory_->ValidPlayerChoices());
    std::string player_token = TTTRules::OtherToken(first_player_token);
    IPlayer *player_two = CreatePlayer(player_type, player_token);
    return player_two;
}

IPlayer * TTTEngine::CreatePlayer(std::string player_type, std::string player_token){
    return factory_->Create(player_type, player_token);
}

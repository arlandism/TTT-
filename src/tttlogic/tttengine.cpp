#include "tttengine.h"

void TTTEngine::StartGame(){
    std::string first_player_type, second_player_type,
                first_player_token, second_player_token,
                play_again_answer;
    
    driver_->Display(UIPresenter::WelcomeBanner());
    first_player_type = driver_->GetPlayerType("first", valid_player_choices);
    first_player_token = driver_->GetToken(valid_token_choices);
    
    second_player_type = driver_->GetPlayerType("second", valid_player_choices);
    second_player_token = TTTRules::OtherToken(first_player_token);
    
    IPlayer *player_one = driver_->CreatePlayer(first_player_type, first_player_token);
    IPlayer *player_two = driver_->CreatePlayer(second_player_type, second_player_token);
    
    Board board = *new Board(3);
    Game game = *new Game(&board, player_one, player_two);
    TTTRules rules = *new TTTRules(&board);
    while (not rules.GameOver()){
        game.Round();
    }
    driver_->Display("\n" + BoardPresenter::Present(board));
    driver_->Display(UIPresenter::PresentWinner(rules.GameWinner()));
}
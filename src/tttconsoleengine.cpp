#include "tttconsoleengine.h"

Player * CreatePlayer(){
    std::string player_type;
    std::string player_token;
    
    std::cout << GamePresenter::PlayerPrompt();
    std::cin >> player_type;
    GamePresenter::TokenPrompt();
    std::cin >> player_token;
    
    MoveStrategy *move_strategy;
    if (player_type == "human"){
        move_strategy = new TerminalInput();
    } else {
        move_strategy = new Minimax(player_token, new TTTSettings());
    }
    return new Player(player_token, move_strategy);
}

void StartGame(std::string first_player_type, std::string first_player_token,
               std::string second_player_type, std::string second_player_token){
    std::cout << GamePresenter::WelcomeBanner();
    Player *player_one = CreatePlayer();
    Player *player_two = CreatePlayer();
    Board *board = new Board(3);
    Game game = *new Game(board, player_one, player_two);
    TTTRules rules = *new TTTRules(board);
    while (not (rules.GameOver())){
        game.Round();
    }
    GamePresenter::PresentWinner(rules);
}

void PromptForReplay(){
    std::cout << GamePresenter::ReplayPrompt();
    std::string answer;
    std::cin >> answer;
  //  if (GamePresenter::AffirmativeAnswer(answer)){
   //     StartGame();
  //  }
}
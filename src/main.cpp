#include <iostream>
#include "game.h"
#include "player.h"
#include "movestrategy.h"
#include "minimax.h"
#include "tttsettings.h"
#include "terminalinput.h"

void PrintWelcomeBanner(){
    std::cout << "***************************\n";
    std::cout << "* Welcome to Tic Tac Toe! *\n";
    std::cout << "***************************\n";
}

void PlayerPrompt(){
    std::cout << "What type of player would you like to be?\n";
}

void TokenPrompt(){
    std::cout << "What's that player's token?\n";
}

void PrintWinner(TTTRules rules){
    std::cout << "And the winner is... " << rules.GameWinner() << "\n";
}

Player * CreatePlayer(){
    std::string player_type;
    std::string player_token;
    
    PlayerPrompt();
    std::cin >> player_type;
    TokenPrompt();
    std::cin >> player_token;
    
    MoveStrategy *move_strategy;
    if (player_type == "human"){
        move_strategy = new TerminalInput();
    } else {
        move_strategy = new Minimax(new TTTSettings("x","o"));
    }
    return new Player(player_token, move_strategy);
}

void StartGame(){
    PrintWelcomeBanner();
    Player *player_one = CreatePlayer();
    Player *player_two = CreatePlayer();
    Board *board = new Board(3);
    Game game = Game(board, player_one, player_two);
    TTTRules rules = *new TTTRules(board, player_one->token(), player_two->token());
    while (not (rules.GameOver())){
        game.Round();
    }
    PrintWinner(rules);
}

void PromptForReplay(){
    std::cout << "Would you like to play again?\n";
    std::string answer;
    std::cin >> answer;
    if (answer == "y"){
        StartGame();
    }
}

int main(int argc, const char * argv[])
{
    StartGame();
    return 0;
}
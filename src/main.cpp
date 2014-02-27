#include <iostream>
#include "game.h"
#include "player.h"
#include "terminalinput.h"
#include "userinputstrategy.h"
#include "minimaxstrategy.h"
#include "tttsettings.h"
#include "vector"

std::string first_player_type, second_player_type,
            first_player_token, second_player_token;

std::vector<std::string> valid_player_choices = {"Human", "AI"};

std::string PromptUserForPlayerType(std::string playerOrder){
    std::string playerType;
    std::string errorPrompt = "Invalid choice, please try again.\n";
    std::cout << "Please tell us about the " << playerOrder << " player.\n";
    std::cout << "Is it Human or AI?\n";
    //playerType = InputValidator::Validate(valid_player_choices, new TerminalInput(), errorPrompt);
    return playerType;
}

std::string GetPlayerToken(){
    std::string playerToken;
    std::cout << "And that player's token?\n";
    std::cin >> playerToken;
    return playerToken;
}

void PrintWelcomeBanner(){
    std::cout << "***************************\n";
    std::cout << "* Welcome to Tic Tac Toe! *\n";
    std::cout << "***************************\n";
}
//
//Player* CreatePlayer(std::string playerType, std::string token){
//    if (playerType == "Human"){
//        return new Player(token, new UserInputStrategy());
//    } else {
//        return new Player(token, new MinimaxStrategy());
//    }
//}

int main(int argc, const char * argv[])
{
    PrintWelcomeBanner();
    first_player_type = PromptUserForPlayerType("first");
    first_player_token = GetPlayerToken();
    second_player_type = PromptUserForPlayerType("second");
    second_player_token = GetPlayerToken();
//  IPlayer *player_one = createPlayer(firstPlayerType, firstPlayerToken);
//    IPlayer *player_two = createPlayer(secondPlayerType, secondPlayerToken);
    Board board = *new Board(3);
//    Game game = *new Game(board, player_one, player_two);
//    game.Round();
//    PrintWinner(game);
    return 0;
}
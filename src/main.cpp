#include <iostream>
#include "game.h"
#include "player.h"
#include "terminalinput.h"
#include "userinputstrategy.h"
#include "minimaxstrategy.h"
#include "vector"

std::string firstPlayerType, secondPlayerType,
            firstPlayerToken, secondPlayerToken;

std::vector<std::string> validPlayerChoices = {"Human", "AI"};

std::string promptUserForPlayerType(std::string playerOrder){
    std::string playerType;
    std::string errorPrompt = "Invalid choice, please try again.\n";
    std::cout << "Please tell us about the " << playerOrder << " player.\n";
    std::cout << "Is it Human or AI?\n";
    //playerType = InputValidator::Validate(validPlayerChoices, new TerminalInput(), errorPrompt);
    return playerType;
}

std::string getPlayerToken(){
    std::string playerToken;
    std::cout << "And that player's token?\n";
    std::cin >> playerToken;
    return playerToken;
}

void printWelcomeBanner(){
    std::cout << "***************************\n";
    std::cout << "* Welcome to Tic Tac Toe! *\n";
    std::cout << "***************************\n";
}

Player* createPlayer(std::string playerType, std::string token){
    if (playerType == "Human"){
        return new Player(token, new UserInputStrategy());
    } else {
        return new Player(token, new MinimaxStrategy());
    }
}

int main(int argc, const char * argv[])
{
    printWelcomeBanner();
    firstPlayerType = promptUserForPlayerType("first");
    firstPlayerToken = getPlayerToken();
    secondPlayerType = promptUserForPlayerType("second");
    secondPlayerToken = getPlayerToken();
    IPlayer *player_one = createPlayer(firstPlayerType, firstPlayerToken);
    IPlayer *player_two = createPlayer(secondPlayerType, secondPlayerToken);
    Board board = *new Board(3);
//    Game game = *new Game(board, player_one, player_two);
//    game.Round();
//    PrintWinner(game);
    return 0;
}
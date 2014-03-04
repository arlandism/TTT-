#include "consolemovestrategy.h"

int ConsoleMoveStrategy::NextMove(Board board){
    TerminalIO io = *new TerminalIO();
    io.Print(BoardPresenter::Present(board));
    io.Print("Please select a valid move from: ");
    io.Print(BoardPresenter::ShowOpenSpaces(board) + "\n");
    std::string input = io.GetInput();
    int move = std::stoi(input);
    return move;
}
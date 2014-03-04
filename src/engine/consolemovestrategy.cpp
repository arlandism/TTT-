#include "consolemovestrategy.h"

int ConsoleMoveStrategy::NextMove(Board board){
    ShowMovePrompt(board);
    std::string input = io_.GetInput();
    int move = std::stoi(input);
    return move;
}

void ConsoleMoveStrategy::ShowMovePrompt(Board board){
    io_.Print("\n" + BoardPresenter::Present(board));
    io_.Print("\nYou're " + token_);
    io_.Print("\nPlease select a valid move from: ");
    io_.Print(BoardPresenter::ShowOpenSpaces(board) + "\n");
}
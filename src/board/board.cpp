#include "board.h"

void Board::Move(int space, std::string token){
    int square_index = space - 1;
    state_[square_index] = token;
}

bool Board::Over(){
    std::string current_winner = winner();
    return (current_winner != "NO WINNER") or Full();
}

std::string Board::winner(){
    std::vector<std::vector<std::string>> winning_combinations = WinningCombinations();
    std::vector<std::vector<std::string>>::const_iterator iterator;
    for (iterator = winning_combinations.begin(); iterator != winning_combinations.end(); iterator++){
        std::vector<std::string> combination = *iterator;
        std::string token = (*iterator).front();
        if (TokensEqual(combination) && AllSpacesFilled(combination)){
            return token;
        }
    }
    return NO_WINNER_;
}

bool Board::Full(){
    std::vector<std::string>::const_iterator iterator;
    for (iterator = state_.begin(); iterator != state_.end(); iterator++){
        std::string token_at_space = *iterator;
        if (token_at_space != ""){
            return true;
        }
    }
    return false;
}

bool Board::TokensEqual(std::vector<std::string> collection){
    return std::equal(collection.begin() + 1, collection.end(), collection.begin());
}

bool Board::AllSpacesFilled(std::vector<std::string> spaces){
    return not EmptySquarePresent(spaces);
}

std::vector<std::vector<std::string>> Board::WinningCombinations(){
    std::vector<std::vector<std::string>> winning_combinations;
    std::vector<std::vector<std::string>> rows = Rows();
    std::vector<std::vector<std::string>> columns = Columns();
    std::vector<std::vector<std::string>> diagonals = Diagonals();
    winning_combinations.insert(winning_combinations.end(), rows.begin(), rows.end());
    winning_combinations.insert(winning_combinations.end(), columns.begin(), columns.end());
    winning_combinations.insert(winning_combinations.end(), diagonals.begin(), diagonals.end());
    return winning_combinations;
}

std::vector<std::vector<std::string>> Board::Rows(){
    BoardSpaces board_spaces = *new BoardSpaces(state_);
    return board_spaces.Rows();
};

std::vector<std::vector<std::string>> Board::Columns(){
    BoardSpaces board_spaces = *new BoardSpaces(state_);
    return board_spaces.Columns();
};

std::vector<std::vector<std::string>> Board::Diagonals(){
    BoardSpaces board_spaces = *new BoardSpaces(state_);
    return board_spaces.Diagonals();
};

bool Board::EmptySquarePresent(std::vector<std::string> spaces){
    std::string empty_square = "";
    return std::find(spaces.begin(), spaces.end(), empty_square) != spaces.end();
}
#include "tttrules.h"

std::string TTTRules::Winner(){
    std::vector<std::vector<std::string>> winning_combinations = WinningCombinations();
    std::vector<std::vector<std::string>>::const_iterator iterator;
    for (iterator = winning_combinations.begin(); iterator != winning_combinations.end(); iterator++){
        std::vector<std::string> combination = *iterator;
        std::string token = (*iterator).front();
        if (TokensEqual(combination) && board_->AllSpacesFilled(combination)){
            return token;
        }
    }
    return NO_WINNER_;
}

bool TTTRules::TokensEqual(std::vector<std::string> collection){
    return std::equal(collection.begin() + 1, collection.end(), collection.begin());
}

std::vector<std::vector<std::string>> TTTRules::WinningCombinations(){
    std::vector<std::vector<std::string>> winning_combinations;
    std::vector<std::vector<std::string>> rows = board_->Rows();
    std::vector<std::vector<std::string>> columns = board_->Columns();
    std::vector<std::vector<std::string>> diagonals = board_->Diagonals();
    winning_combinations.insert(winning_combinations.end(), rows.begin(), rows.end());
    winning_combinations.insert(winning_combinations.end(), columns.begin(), columns.end());
    winning_combinations.insert(winning_combinations.end(), diagonals.begin(), diagonals.end());
    return winning_combinations;
}
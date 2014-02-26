#ifndef __TTT____tttrules__
#define __TTT____tttrules__

#include "board.h"
#include <iostream>

class TTTRules {

public:
    
    TTTRules(Board *board, std::string token_one, std::string token_two){
        board_ = board;
        token_one_ = token_one;
        token_two_ = token_two;
    };
    
    std::string Winner();
    bool Over();
    
private:
    Board *board_;
    std::string token_one_;
    std::string token_two_;
    std::string NO_WINNER_ = "NO WINNER";
    
    bool TokensEqual(std::vector<std::string>);
    std::vector<std::vector<std::string>> WinningCombinations();
    std::vector<std::vector<std::string>> DiagonalWins();
    std::vector<std::vector<std::string>> RowWins();
    std::vector<std::vector<std::string>> ColumnWins();
};

#endif

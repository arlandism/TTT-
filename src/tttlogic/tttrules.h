#ifndef __TTT____tttrules__
#define __TTT____tttrules__

#include <string>
#include "board.h"

class TTTRules {

public:
    
    TTTRules(Board *board){
        board_ = board;
    };
    
    std::string GameWinner();
    bool GameOver();
    static std::string OtherToken(std::string);
    
private:
    
    Board *board_;
    std::string NO_WINNER_ = board_->EmptySpace;
    
    bool TokensEqual(std::vector<std::string>);
    std::vector<std::vector<std::string>> WinningCombinations();
    std::vector<std::vector<std::string>> DiagonalWins();
    std::vector<std::vector<std::string>> RowWins();
    std::vector<std::vector<std::string>> ColumnWins();
};

#endif
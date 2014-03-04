#ifndef __TTT____consolemovestrategy__
#define __TTT____consolemovestrategy__

#include "board.h"
#include "boardpresenter.h"
#include "movestrategy.h"
#include "terminalio.h"

class ConsoleMoveStrategy: public MoveStrategy {
    
public:
    
    ConsoleMoveStrategy(std::string token){
        token_ = token;
    }
    
    int NextMove(Board);
    
private:
    
    std::string token_;
    TerminalIO io_ = *new TerminalIO();
    
    void ShowMovePrompt(Board);
};

#endif
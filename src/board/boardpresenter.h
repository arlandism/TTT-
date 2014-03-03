#ifndef __TTT____boardpresenter__
#define __TTT____boardpresenter__

#include <iostream>
#include <stdio.h>
#include "board.h"
#include "vector"
#include "boardspaces.h"

class BoardPresenter {
    
public:
    
    static std::string Present(Board);
    
private:
    const static std::string LINE_SEPARATOR;
    const static std::string TOKEN_SEPARATOR;
    
    static std::string FormatToken(std::string);
    static std::string FormatRow(std::vector<std::string>);
    static std::string JoinMiddle(std::vector<std::string>);
};
#endif

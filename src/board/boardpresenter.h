#ifndef __TTT____boardpresenter__
#define __TTT____boardpresenter__

#include <string>
#include <stdio.h>
#include <vector>
#include "board.h"
#include "boardspaces.h"

class BoardPresenter{
    
public:
    
    static std::string Present(Board);
    static std::string ShowOpenSpaces(Board);
    
private:
    const static std::string LINE_SEPARATOR;
    const static std::string TOKEN_SEPARATOR;
    
    static std::string FormatToken(std::string);
    static std::string FormatRow(std::vector<std::string>);
    static std::string JoinMiddle(std::vector<std::string>);
};
#endif

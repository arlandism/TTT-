#ifndef __TTT____gamepresenter__
#define __TTT____gamepresenter__

#include "board.h"
#include <iostream>
#include "vector"

class GamePresenter {
    
public:
    
    static std::string WelcomeBanner();
    static std::string PlayerPrompt(std::vector<std::string>);
    static std::string TokenPrompt();
    static std::string PresentWinner(std::string);
};

#endif

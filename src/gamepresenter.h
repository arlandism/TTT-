#ifndef __TTT____gamepresenter__
#define __TTT____gamepresenter__

#include <iostream>
#include "tttrules.h"

class GamePresenter {
    
public:
    
    static std::string WelcomeBanner();
    static std::string PlayerPrompt();
    static std::string TokenPrompt();
    static std::string PresentWinner(TTTRules rules);
    static std::string ReplayPrompt();
    static bool AffirmativeAnswer(std::string);
};

#endif

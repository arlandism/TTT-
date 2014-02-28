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
    static std::string PresentChoices(std::vector<std::string>);
    static bool AffirmativeAnswer(std::string);
};

#endif

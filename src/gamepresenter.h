#ifndef __TTT____gamepresenter__
#define __TTT____gamepresenter__

#include <iostream>
#include "vector"

class GamePresenter {
    
public:
    
    static std::string WelcomeBanner();
    static std::string PlayerPrompt();
    static std::string TokenPrompt();
    static std::string PresentWinner(std::string);
    static std::string ReplayPrompt();
    static std::string PresentPlayerChoices(std::vector<std::string>);
    static bool AffirmativeAnswer(std::string);
};

#endif

#ifndef __TTT____uipresenter__
#define __TTT____uipresenter__

#include <string>
#include <vector>

#include "board.h"

class UIPresenter{
    
public:
    
    static std::string WelcomeBanner();
    static std::string PlayerPrompt(std::string, std::vector<std::string>);
    static std::string TokenPrompt(std::vector<std::string>);
    static std::string PresentWinner(std::string);
    
private:
    
    static std::string JoinChoices(std::vector<std::string>);
};

#endif

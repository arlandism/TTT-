#ifndef __TTT____uidriver__
#define __TTT____uidriver__

#include <string>
#include <vector>
#include "board.h"
#include "boardpresenter.h"
#include "uipresenter.h"
#include "inputvalidator.h"
#include "io.h"

class UIDriver {
    
public:
    
    UIDriver(IO *io){
        io_ = io;
    }
    
    std::string GetPlayerType(std::string, std::vector<std::string>);
    std::string GetToken(std::vector<std::string>);
    void Display(std::string);
    void DisplayWelcome();
    void DisplayBoard(Board);
    void DisplayWinner(std::string);
    
private:
    
    IO *io_;
    std::string used_token_;
    
    std::string GetFromUser(std::vector<std::string>, std::string);
};
#endif

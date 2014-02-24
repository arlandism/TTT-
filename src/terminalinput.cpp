#include <iostream>
#include "terminalinput.h"

int TerminalInput::Call(){
    int input;
    std::cin >> input;
    return input;
}
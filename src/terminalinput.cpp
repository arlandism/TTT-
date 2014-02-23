#include <iostream>
#include "terminalinput.h"

int TerminalInput::call(){
    int input;
    std::cin >> input;
    return input;
}
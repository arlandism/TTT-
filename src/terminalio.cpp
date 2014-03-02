#include "terminalio.h"

std::string TerminalIO::GetInput(){
    std::string input;
    std::cin >> input;
    return input;
}
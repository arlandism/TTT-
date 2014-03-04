#include "terminalio.h"

std::string TerminalIO::GetInput(){
    std::string input;
    std::cin >> input;
    return input;
}

void TerminalIO::Print(std::string message){
    std::cout << message;
}
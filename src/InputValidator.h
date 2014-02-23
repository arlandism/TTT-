#ifndef __TTT____InputValidator__
#define __TTT____InputValidator__

#include "input.h"
#include "vector"

class InputValidator{
    
public:
    static int validate(std::vector<int> validInputs, Input* input);
    static bool IsValidInput(std::vector<int> validInputs, int input);
};

#endif
#ifndef __TTT____InputValidator__
#define __TTT____InputValidator__

#include "input.h"
#include "vector"

class InputValidator{
    
public:
    static int Validate(std::vector<int>, Input*);
    static bool IsValidInput(std::vector<int>, int);
};

#endif
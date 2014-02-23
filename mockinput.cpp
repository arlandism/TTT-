#include "mockinput.h"

int MockInput::call(){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
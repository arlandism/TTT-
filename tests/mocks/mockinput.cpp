#include "mockinput.h"

int MockInput::Call(){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
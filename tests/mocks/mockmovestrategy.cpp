#include "mockmovestrategy.h"

int MockMoveStrategy::Execute(){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
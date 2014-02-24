#include "mockmovestrategy.h"

int MockMoveStrategy::NextMove(){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
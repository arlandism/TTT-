#include "mockmovestrategy.h"

int MockMoveStrategy::NextMove(Board board){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
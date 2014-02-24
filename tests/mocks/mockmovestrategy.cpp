#include "mockmovestrategy.h"

int MockMoveStrategy::NextMove(std::vector<int> board){
    int nextReturnValue = inputsToReturn.back();
    inputsToReturn.pop_back();
    return nextReturnValue;
}
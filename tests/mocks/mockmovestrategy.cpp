#include "mockmovestrategy.h"

int MockMoveStrategy::NextMove(Board board){
    int next_return_value = inputs_to_return.back();
    inputs_to_return.pop_back();
    return next_return_value;
}
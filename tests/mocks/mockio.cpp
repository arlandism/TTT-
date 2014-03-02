#include "mockio.h"

std::string MockIO::GetInput(){
    std::string next_return_value = inputs_to_return.back();
    inputs_to_return.pop_back();
    return next_return_value;
}

void MockIO::Print(std::string message){}
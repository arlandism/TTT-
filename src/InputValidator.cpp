#include "inputvalidator.h"

bool InputValidator::IsValid(std::vector<std::string> valid_inputs, std::string input){
    std::vector<std::string>::const_iterator start = valid_inputs.begin();
    std::vector<std::string>::const_iterator end = valid_inputs.end();
    return std::find(start, end, input) != end;
}
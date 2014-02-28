#include "inputvalidator.h"

bool InputValidator::IsValid(std::vector<std::string> valid_inputs, std::string input){
    return std::find(valid_inputs.begin(), valid_inputs.end(), input) != valid_inputs.end();
}
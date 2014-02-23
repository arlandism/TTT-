#include "inputvalidator.h"
#include <vector>

int InputValidator::validate(std::vector<int> validInputs, Input *input){
    int userInput = input->call();
    if (InputValidator::IsValidInput(validInputs, userInput)){
        return userInput;
    } else {
        return validate(validInputs, input);
    }
};

bool InputValidator::IsValidInput(std::vector<int> validInputs, int input){
    return std::find(validInputs.begin(), validInputs.end(), input) != validInputs.end();
}

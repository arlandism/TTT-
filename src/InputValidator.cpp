#include "inputvalidator.h"

int InputValidator::Validate(std::vector<int> validInputs, Input *input){
    int userInput = input->Call();
    if (InputValidator::IsValidInput(validInputs, userInput)){
        return userInput;
    } else {
        return Validate(validInputs, input);
    }
};

bool InputValidator::IsValidInput(std::vector<int> validInputs, int input){
    return std::find(validInputs.begin(), validInputs.end(), input) != validInputs.end();
}
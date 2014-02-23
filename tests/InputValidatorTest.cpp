#include "catch.hpp"
#include "inputvalidator.h"
#include "mockinput.h"
#include "vector"

TEST_CASE("InputValidator keeps asking for input until it is valid" "[inputvalidator]"){
    std::vector<int> validInputs = {1};
    std::vector<int> inputsToReturn = {4, 1};
    Input *input = new MockInput(inputsToReturn);
    REQUIRE(1 == InputValidator::validate(validInputs, input));
}
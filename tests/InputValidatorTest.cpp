#include "catch.hpp"
#include "inputvalidator.h"
#include "mockinput.h"

TEST_CASE("InputValidator rejects bad input" "[inputvalidator]"){
    int validInputs[] = {1};
    int inputs[2] = {4, 1};
    MockInput input = *new MockInput(inputs);
    REQUIRE(1 == InputValidator::validate(validInputs, input));
}
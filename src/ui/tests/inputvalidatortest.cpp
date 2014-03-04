#include "catch.hpp"
#include "inputvalidator.h"
#include "vector"

TEST_CASE("InputValidator::IsValid returns..."){
    
    SECTION("false when the input isn't valid"){
        std::vector<std::string> validInputs = { "Foo" };
        std::string input = "HI";
        REQUIRE(false == InputValidator::IsValid(validInputs, input));
    }
    
    SECTION("true when the input is valid"){
        std::vector<std::string> validInputs = { "Foo" };
        std::string input = "Foo";
        REQUIRE(true == InputValidator::IsValid(validInputs, input));
    }
}
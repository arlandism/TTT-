#include "catch.hpp"
#include "mockio.h"
#include "mockplayerfactory.h"
#include "uidriver.h"

TEST_CASE("UIDriver::GetPlayerType keeps asking until it gets valid choice from user"){
    std::vector<std::string> valid_player_choices = {"Human"};
    std::vector<std::string> return_values = {"Foo", "Human"};
    MockIO mock_io = *new MockIO(return_values);
    UIDriver driver = *new UIDriver(&mock_io);
    REQUIRE("Human" == driver.GetPlayerType("", valid_player_choices));
}

TEST_CASE("UIDriver::GetToken keeps asking until it gets valid choice from user"){
    std::vector<std::string> valid_token_choices = {"x"};
    std::vector<std::string> return_values = {"f", "x"};
    MockIO mock_io = *new MockIO(return_values);
    UIDriver driver = *new UIDriver(&mock_io);
    REQUIRE("x" == driver.GetToken(valid_token_choices));
}

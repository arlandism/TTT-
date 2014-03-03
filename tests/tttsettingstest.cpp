#include "catch.hpp"
#include "board.h"
#include "minimax.h"
#include "tttsettings.h"

TEST_CASE("TTTSettings::OtherToken returns opponent's token"){
    TTTSettings settings = *new TTTSettings();
    settings.token_one = "a";
    settings.token_two = "b";
    REQUIRE("a" == settings.OtherToken("b"));
    REQUIRE("b" == settings.OtherToken("a"));
}
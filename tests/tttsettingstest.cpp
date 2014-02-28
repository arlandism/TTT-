#include "catch.hpp"
#include "board.h"
#include "minimax.h"
#include "tttsettings.h"

TEST_CASE("TTTSettings::OtherToken returns opponent's token"){
    TTTSettings::set_token_one("a");
    TTTSettings::set_token_two("b");
//    REQUIRE("a" == TTTSettings::OtherToken("b"));
//    REQUIRE("b" == TTTSettings::OtherToken("a"));
}
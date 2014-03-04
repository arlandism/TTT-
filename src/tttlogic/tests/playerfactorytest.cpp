#include "catch.hpp"
#include "playerfactory.h"

TEST_CASE("PlayerFactory::Create generates players with given token"){
    PlayerFactory factory = *new PlayerFactory();
    std::string player_type = factory.ValidPlayerChoices().front();
    std::string token = "x";
    IPlayer *player = factory.Create(player_type, token);
    REQUIRE("x" == player->token());
}

TEST_CASE("PlayerFactory::Create raises exception given invalid player choice"){
    PlayerFactory factory = *new PlayerFactory();
    std::string player_type = "Arlandis";
    std::string token = "x";
    REQUIRE_THROWS(factory.Create(player_type, token));
}
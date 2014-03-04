#include "catch.hpp"
#include "mockplayerfactory.h"
#include "mockio.h"
#include "uidriver.h"
#include "tttengine.h"

MockPlayerFactory mock_factory = *new MockPlayerFactory();

TEST_CASE("TTTEngine::CreatePlayerOne..."){
    
    std::vector<std::string> inputs_to_return = {"x", "Human"};
    MockIO mock_io = *new MockIO(inputs_to_return);
    UIDriver driver = *new UIDriver(&mock_io);
    
    SECTION("creates a player"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayerOne();
        REQUIRE(true == mock_factory.LastPlayerType("Human"));
    }
    
    SECTION("creates a player with supplied token"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayerOne();
        REQUIRE(true == mock_factory.LastPlayerToken("x"));
    }
    
}

TEST_CASE("TTTEngine::CreatePlayerTwo..."){
    
    std::vector<std::string> inputs_to_return = {"Human"};
    std::string player_one_token = "x";
    MockIO mock_io = *new MockIO(inputs_to_return);
    UIDriver driver = *new UIDriver(&mock_io);
    
    SECTION("create players"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayerTwo(player_one_token);
        REQUIRE(true == mock_factory.LastPlayerType("Human"));
    }
    
    SECTION("create players with opposite token of the first player"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayerTwo(player_one_token);
        REQUIRE(true == mock_factory.LastPlayerToken("o"));
    }
    
}
#include "catch.hpp"
#include "mockio.h"
#include "mockplayerfactory.h"
#include "tttengine.h"


TEST_CASE("TTTEngine::CreatePlayer uses user input to..."){
    
    MockPlayerFactory mock_factory = *new MockPlayerFactory();
    MockIO mock_io = *new MockIO();
    
    SECTION("create players"){
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerType("Human"));
    }

    SECTION("create players with tokens"){
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerToken("x"));
    }
}
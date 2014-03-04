#include "catch.hpp"
#include "mockplayerfactory.h"
#include "mockio.h"
#include "uidriver.h"
#include "tttengine.h"

MockPlayerFactory mock_factory = *new MockPlayerFactory();

TEST_CASE("TTTEngine::CreatePlayer uses user input to..."){
    
    MockIO mock_io = *new MockIO();
    UIDriver driver = *new UIDriver(&mock_io);
    
    SECTION("create players"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerType("Human"));
    }
    
    SECTION("create players with tokens"){
        TTTEngine engine = *new TTTEngine(&driver, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerToken("x"));
    }
    
}
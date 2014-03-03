#include "catch.hpp"
#include "mockio.h"
#include "mockplayerfactory.h"
#include "tttengine.h"

MockPlayerFactory mock_factory = *new MockPlayerFactory();

TEST_CASE("TTTEngine::CreatePlayer uses user input to..."){
    
    SECTION("create players"){
        std::vector<std::string> inputs_to_return = {"Human"};
        MockIO mock_io = *new MockIO(inputs_to_return);
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerType("Human"));
    }

    SECTION("create players with tokens"){
       std::vector<std::string> inputs_to_return = {"x"};
        MockIO mock_io = *new MockIO(inputs_to_return);
        IO *io = &mock_io;
        MockPlayerFactory *mock_factory = new MockPlayerFactory();
        TTTEngine engine = *new TTTEngine(io, mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory->LastPlayerToken("x"));
    }
}
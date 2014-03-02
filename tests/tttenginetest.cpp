#include "catch.hpp"
#include "mockio.h"
#include "mockplayerfactory.h"
#include "tttengine.h"

TEST_CASE("TTTEngine::GetPlayerType prompts player for type"){
    std::vector<std::string> inputs_to_return = {"Human"};
    MockIO mock_io = *new MockIO(inputs_to_return);
    IO *io = &mock_io;
    TTTEngine engine = *new TTTEngine(io);
    REQUIRE("Human" == engine.GetPlayerType());
}

TEST_CASE("TTTEngine::GetToken prompts player for token"){
    std::vector<std::string> inputs_to_return = {"x"};
    MockIO mock_io = *new MockIO(inputs_to_return);
    IO *io = &mock_io;
    TTTEngine engine = *new TTTEngine(io);
    REQUIRE("x" == engine.GetToken());
}

TEST_CASE("TTTEngine::CreatePlayer uses user input to..."){
    
    SECTION("create players"){
        std::vector<std::string> inputs_to_return = {"Human"};
        MockIO mock_io = *new MockIO(inputs_to_return);
        IO *io = &mock_io;
        MockPlayerFactory *mock_factory = new MockPlayerFactory();
        TTTEngine engine = *new TTTEngine(io, mock_factory);
//        REQUIRE(true == mock_factory->LastPlayerTypeCalledWith("Human"));
    }

    SECTION("create players with tokens"){
       std::vector<std::string> inputs_to_return = {"x"};
        MockIO mock_io = *new MockIO(inputs_to_return);
        IO *io = &mock_io;
        MockPlayerFactory *mock_factory = new MockPlayerFactory();
        TTTEngine engine = *new TTTEngine(io, mock_factory);
//        REQUIRE(true == mock_factory->LastPlayerTokenCalledWith("x"));
    }
}
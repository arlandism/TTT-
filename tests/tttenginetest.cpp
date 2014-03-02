#include "catch.hpp"
#include "io.h"
#include "mockio.h"
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

TEST_CASE("TTTEngine::"){
    
}
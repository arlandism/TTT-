#include "catch.hpp"
#include "mockio.h"
#include "mockplayerfactory.h"
#include "tttengine.h"

MockPlayerFactory mock_factory = *new MockPlayerFactory();

TEST_CASE("TTTEngine::CreatePlayer uses user input to..."){
    
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
    
    SECTION("doesn't allow the same token choice twice"){
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        engine.CreatePlayer("Human", "x");
        REQUIRE(true == mock_factory.LastPlayerToken("x"));
    }
    
}

// Tests coupled to the primary use-case

TEST_CASE("TTTEngine::GetPlayerType keeps asking until it gets Human or AI choice from user"){
    
    SECTION("Human"){
        std::vector<std::string> return_values = {"Foo", "Human"};
        MockIO mock_io = *new MockIO(return_values);
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        REQUIRE("Human" == engine.GetPlayerType());
    }
    
    SECTION("AI"){
        std::vector<std::string> return_values = {"Foo", "AI"};
        MockIO mock_io = *new MockIO(return_values);
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        REQUIRE("AI" == engine.GetPlayerType());
    }

}

TEST_CASE("TTTEngine::GetToken keeps asking until it gets valid choice from user"){
    
    SECTION("x"){
        std::vector<std::string> return_values = {"f", "x"};
        MockIO mock_io = *new MockIO(return_values);
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        REQUIRE("x" == engine.GetToken());
    }
    
    SECTION("o"){
        std::vector<std::string> return_values = {"g", "o"};
        MockIO mock_io = *new MockIO(return_values);
        TTTEngine engine = *new TTTEngine(&mock_io, &mock_factory);
        REQUIRE("o" == engine.GetToken());
    }
}
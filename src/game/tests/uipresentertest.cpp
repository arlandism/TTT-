#include "catch.hpp"
#include "board.h"
#include "uipresenter.h"

TEST_CASE("UIPresenter::PresentWinner..."){
    
    SECTION("shows the winning token"){
        std::string winner = "x";
        std::string expected_display = "\nAnd the winner is... " + winner + "\n";
        REQUIRE(expected_display == UIPresenter::PresentWinner(winner));
    }
    
    SECTION("says, 'It's a tie!' if there's no winner"){
        std::string winner = "";
        std::string expected_display = "\nIt's a tie!\n";
        REQUIRE(expected_display == UIPresenter::PresentWinner(winner));
    }
}
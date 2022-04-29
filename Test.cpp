#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "doctest.h"
#include <exception>
using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


 // Test to see the following exceptions: Not player's turn, player doesn't perform coup when he has 10 coins
 // In the meanwhile, it tests whether the turn() method works properly, as well as income() and more to
 // what's being said here.
TEST_CASE("Player's turn - 10 coins - check methods"){
    /*Set game and players*/
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Captain captain{game, "Reut"};
    Contessa contessa{game, "Gilad"};

    for (int i = 0; i < 10; ++i) {
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }

    /*Check if players have 10 coins as expected*/
    CHECK(duke.coins() == 10);
    CHECK(assassin.coins() == 10);
    CHECK(ambassador.coins() == 10);
    CHECK(captain.coins() == 10);
    CHECK(contessa.coins() == 10);


    /*Check if methods work on the way, and if 10 coins other operation exception*/
    CHECK_THROWS(contessa.foreign_aid()); /*Not player's turn*/
    CHECK(game.turn() == "Moshe");
    CHECK_THROWS(duke.tax());
    CHECK_NOTHROW(duke.coup(contessa););
    CHECK(game.players().size() == 4);

    CHECK_THROWS(contessa.foreign_aid()); /*Not player's turn*/
    CHECK(game.turn() == "Yossi");
    CHECK_THROWS(assassin.income());
    CHECK_NOTHROW(assassin.coup(captain););
    CHECK(game.players().size() == 3);

    CHECK_THROWS(contessa.foreign_aid()); /*Not player's turn*/
    CHECK(game.turn() == "Meirav");
    CHECK_THROWS(ambassador.transfer(duke, assassin));
    CHECK_NOTHROW(ambassador.coup(duke););
    CHECK(game.players().size() == 2);
}

// Test if each player's attack works properly as should,
// followed by game's rules.
TEST_CASE("Player's attack performances"){
    /*Set game and players*/
    Game game{};
    Duke duke{game, "Moshe"};
    Assassin assassin{game, "Yossi"};
    Ambassador ambassador{game, "Meirav"};
    Captain captain{game, "Reut"};
    Contessa contessa{game, "Gilad"};


    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();

    /*Check if players have 2 coins as expected*/
    CHECK(duke.coins() == 2);
    CHECK(assassin.coins() == 2);
    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 2);
    CHECK(contessa.coins() == 2);

    /*Duke's tax*/
    CHECK_NOTHROW(duke.tax());
    CHECK(duke.coins() == 5);

    CHECK_NOTHROW(assassin.income()); /*Skip assassin operation for now*/
    CHECK(assassin.coins() == 3);

    /*Ambassador's transfer*/
    CHECK_NOTHROW(ambassador.transfer(duke, assassin));
    CHECK(duke.coins() == 4);
    CHECK(assassin.coins() == 4);

    /*captain's steal*/
    CHECK_NOTHROW(captain.steal(duke));
    CHECK(captain.coins() == 4); /*had 2, now 4*/
    CHECK(duke.coins() == 2);    /*had 4, now 2*/

    CHECK_NOTHROW(contessa.income()); /*Skip contessa operation for now*/
    CHECK_NOTHROW(duke.income()); /*Skip duke operation for now*/

    CHECK_NOTHROW(assassin.coup(captain));
    CHECK(game.players().size() == 4);
    CHECK(assassin.coins() == 1); /*Check if operation has cost 3 coins instead of 7*/

    /*Contessa's block*/
    CHECK(game.turn() == "Meirav"); /*Captain has removed from game*/
    CHECK_NOTHROW(contessa.block(assassin));
    CHECK(game.players().size() == 5); /*Player rejoins the game*/
}
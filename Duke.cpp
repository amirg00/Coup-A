#include "Duke.hpp"
using namespace coup;
using std::move; using std::runtime_error;

//Constructor
Duke::Duke(Game& game, string name)
:Player(game, move(name), "Duke")
{}

void Duke::tax() {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= 10) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    this->increase(3);
    _game.next_turn();
}

void Duke::block(Player& target) {
    if (target.getCurrState() != State::FOREIGN_AID) {
        throw runtime_error("ERR: cannot take double income - targeted player's turn has already reached.");
    }
    target.decrease(2);
    target.setDoubleIncomeBlock(true);
}

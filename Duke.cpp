#include "Duke.hpp"
using std::move;

//Constructor
Duke::Duke(Game& game, string name)
:Player(game, move(name), "Duke")
{}

void Duke::tax() {
    if (!isPlayerTurn()) {throw std::exception();}
    if (_coins >= 10) {throw std::exception();}
    this->increase(3);
    _game.next_turn();
}

void Duke::block(Player& target) {
    if (target.getCurrState() != State::FOREIGN_AID) {throw std::exception();}
    target.decrease(2);
    target.setDoubleIncomeBlock(true);
}

#include "Duke.hpp"
using namespace coup;
using std::move;

//Constructor
Duke::Duke(Game& game, string name)
:Player(game, move(name), "Duke")
{}

void Duke::tax() {
    if (!isPlayerTurn()) {throw "ERR: not player's turn!";}
    if (_coins >= 10) {throw "ERR: player has 10 coins and didn't perform coup.";}
    this->increase(3);
    _game.next_turn();
}

void Duke::block(Player& target) {
    if (target.getCurrState() != State::FOREIGN_AID) {throw std::exception();}
    target.decrease(2);
    target.setDoubleIncomeBlock(true);
}

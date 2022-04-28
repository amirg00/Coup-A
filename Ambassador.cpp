#include "Ambassador.hpp"
using namespace coup;
using std::move;

//Constructor
Ambassador::Ambassador(Game& game, string name)
:Player(game, move(name), "Ambassador")
{}

void Ambassador::transfer(Player& from, Player& to) {
    if (!isPlayerTurn()) {throw "ERR: not player's turn!";}
    if (_coins >= 10) {throw "ERR: player has 10 coins and didn't perform coup.";}
    from.decrease(1);
    to.increase(1);
    _game.next_turn();
}

void Ambassador::block(Player& target) {
    if (target.getCurrState() != State::STEAL) {throw std::exception();}
    target.setStealBlock(true);
}

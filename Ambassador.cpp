#include "Ambassador.hpp"
using namespace coup;
using std::move;

//Constructor
Ambassador::Ambassador(Game& game, string name)
:Player(game, move(name), "Ambassador")
{}

void Ambassador::transfer(Player& from, Player& to) {
    if (!isPlayerTurn()) {throw std::exception();}
    if (_coins >= 10) {throw std::exception();}
    from.decrease(1);
    to.increase(1);
    _game.next_turn();
}

void Ambassador::block(Player& target) {
    if (target.getCurrState() != State::STEAL) {throw std::exception();}
    target.setStealBlock(true);
}

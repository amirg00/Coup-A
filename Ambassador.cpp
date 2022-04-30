#include "Ambassador.hpp"
using namespace coup;
using std::move; using std::runtime_error;

//Constructor
Ambassador::Ambassador(Game& game, string name)
:Player(game, move(name), "Ambassador")
{}

void Ambassador::transfer(Player& from, Player& to) {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= LIMIT) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    from.decrease(1);
    to.increase(1);
    _game.next_turn();
}

void Ambassador::block(Player& target) {
    if (target.getCurrState() != State::STEAL) {throw runtime_error("ERR: cannot block steal - targeted player's turn has already reached.");}
    target.setStealBlock(true);
    target.decrease(2);
    target.getPlayer_ptr().increase(2);
}

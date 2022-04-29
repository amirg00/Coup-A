#include "Captain.hpp"
using namespace coup;
using std::move; using std::runtime_error;

//Constructor
Captain::Captain(Game& game, string name)
:Player(game, move(name), "Captain")
{}

void Captain::steal(Player& target) {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= 10) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    if (_stealBlock){
        setStealBlock(false);
        _game.next_turn();
        return;
    }
    this->increase(2);
    target.decrease(2);
    _game.next_turn();
}

void Captain::block(Player& target) {
    if (target.getCurrState() != State::STEAL) {throw runtime_error("ERR: cannot steal - targeted player's turn has already reached.");}
    target.setStealBlock(true);
}

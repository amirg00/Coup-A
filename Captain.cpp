#include "Captain.hpp"
using namespace coup;
using std::move;

//Constructor
Captain::Captain(Game& game, string name)
:Player(game, move(name), "Captain")
{}

void Captain::steal(Player& target) {
    if (!isPlayerTurn()) {throw "ERR: not player's turn!";}
    if (_coins >= 10) {throw "ERR: player has 10 coins and didn't perform coup.";}
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
    if (target.getCurrState() != State::STEAL) {throw std::exception();}
    target.setStealBlock(true);
}

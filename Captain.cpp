#include "Captain.hpp"
using namespace coup;
using std::move;

//Constructor
Captain::Captain(Game& game, string name)
:Player(game, move(name), "Captain")
{}

void Captain::steal(Player& target) {
    if (!isPlayerTurn()) {throw std::exception();}
    if (_coins >= 10) {throw std::exception();}
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

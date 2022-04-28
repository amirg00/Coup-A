#include "Contessa.hpp"
using namespace coup;
using std::move;

//Constructor
Contessa::Contessa(Game& game, string name)
:Player(game, move(name), "Contessa")
{}

void Contessa::block(Player& target) {
    if (target.getCurrState() != State::COUP) {throw std::exception();}
    target.setCoupBlock(true);
    _game.setPlayers(target.getPlayers());
}

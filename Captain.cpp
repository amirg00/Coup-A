#include "Captain.hpp"
using namespace coup;
using std::move; using std::runtime_error;

//Constructor
Captain::Captain(Game& game, string name)
:Player(game, move(name), "Captain")
{}

void Captain::steal(Player& target) {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= LIMIT) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    _curr_operation = State::STEAL;

    if (target.coins() < STEAL_CHARGE){
        this->increase(target.coins());
        target.decrease(target.coins());
        _steal_coins = target.coins();
    }
    else{ /* Captain steals what target player has*/
        this->increase(STEAL_CHARGE);
        target.decrease(STEAL_CHARGE);
        _steal_coins = STEAL_CHARGE;
    }
    _player_ptr = &target; /*Set target for invert after getting blocked*/
    _game.next_turn();
}

void Captain::block(Player& target) {
    if (target.getCurrState() != State::STEAL) {throw runtime_error("ERR: cannot block steal - targeted player's turn has already reached.");}
    target.setStealBlock(true);
    target.decrease(target.getStealAmount());
    target.getPlayer_ptr().increase(target.getStealAmount());
}

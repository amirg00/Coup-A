#include "Player.hpp"
#include "Game.hpp"

class Captain : public Player{
public:
    Captain(Game& game, string name);
    void steal(Player& target);
    void block(Player& target);
};


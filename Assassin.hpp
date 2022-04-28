#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Assassin : public Player{
    public:
        Assassin(Game& game, string name);
    };
}

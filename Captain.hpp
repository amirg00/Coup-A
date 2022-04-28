#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Captain : public Player{
    public:
        Captain(Game& game, string name);
        void steal(Player& target);
        void block(Player& target);
    };
}

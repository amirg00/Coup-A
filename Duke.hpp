#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Duke : public Player{
    public:
        Duke(Game& game, string name);
        void tax();
        void block(Player& target); /*Blocks doubled income operation*/
    };
}


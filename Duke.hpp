#pragma once
#include "Player.hpp"

namespace coup{
    class Duke : public Player{
    public:
        Duke(Game& game, string name);
        void tax();
        static void block(Player& target); /*Blocks doubled income operation*/
    };
}


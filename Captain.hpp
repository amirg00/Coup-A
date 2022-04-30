#pragma once
#include "Player.hpp"

namespace coup{
    class Captain : public Player{
    public:
        Captain(Game& game, string name);
        void steal(Player& target);
        static void block(Player& target);
    };
}

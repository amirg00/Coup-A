#pragma once
#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game& game, string name);
        void transfer(Player& from, Player& to);
        static void block(Player& target); /*Blocks stealing operation*/
    };
}
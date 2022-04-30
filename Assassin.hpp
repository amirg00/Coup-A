#pragma once
#include "Player.hpp"

namespace coup{
    class Assassin : public Player{
    public:
        Assassin(Game& game, string name);
    };
}

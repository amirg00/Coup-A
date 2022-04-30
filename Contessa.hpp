#pragma once
#include "Player.hpp"

namespace coup{
    class Contessa : public Player{
    public:
        Contessa(Game& game, string name);
        void block(Player& target); /*Blocks assassination*/
    };
}

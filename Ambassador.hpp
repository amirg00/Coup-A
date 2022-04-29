#include "Player.hpp"
#include "Game.hpp"


namespace coup{
    class Ambassador : public Player{
    public:
        Ambassador(Game& game, string name);
        void transfer(Player& from, Player& to);
        void block(Player& target); /*Blocks stealing operation*/
    };
}
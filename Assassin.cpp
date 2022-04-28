#include "Assassin.hpp"
using namespace coup;
using std::move;

//Constructor
Assassin::Assassin(Game& game, string name)
:Player(game, move(name), "Assassin")
{}

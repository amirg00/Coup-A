#include "Assassin.hpp"
using std::move;

//Constructor
Assassin::Assassin(Game& game, string name)
:Player(game, move(name), "Assassin")
{}

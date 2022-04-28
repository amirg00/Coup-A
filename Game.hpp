#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::string; using std::vector; using std::remove; using std::cout; using std::endl; using std::transform;

namespace coup{
    class Game {
    private:
        string _winner;            /* Winner's name*/
        int _curr_turn;            /* Index for player's position*/
        vector<string> _players;   /* Players name vector*/
    public:
        Game();                    /*Constructor*/
        string turn();
        void next_turn();
        vector<string> players();
        string winner();
        void addPlayer(const string& name);
        void remPlayer(const string& name);
        void setPlayers(const vector<string>& players);
    };
}
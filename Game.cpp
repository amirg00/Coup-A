#include "Game.hpp"


Game::Game() {
    _winner = "";
    _curr_turn = 0;
}

vector<string> Game::players() {
    return _players;
}

string Game::turn() {
    return _players[(unsigned long)_curr_turn];
}

void Game::next_turn() {
    //cout << "Size: " << (int)_players.size() << endl;
    ++_curr_turn;
    _curr_turn %= (int)_players.size();
}

string Game::winner() {
    return _winner;
}

void Game::addPlayer(const string &name) {
    _players.push_back(name);
}

void Game::remPlayer(const string &name) {
    _players.erase(remove(_players.begin(), _players.end(), name), _players.end());
}

void Game::setPlayers(const vector<string>& players) {
    _players.clear();
    for(const string& player: players){_players.push_back(player);}
}


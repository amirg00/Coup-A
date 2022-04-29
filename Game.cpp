#include "Game.hpp"
using namespace coup;

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

/**
 * Fixes the current position after removing the player with the given name.
 * @param remPlayerName
 */
void Game::fixCurrPos(const string &remPlayerName) {
    size_t pos = 0;
    for (size_t i = 0; i < _players.size(); ++i) {
        if (_players[i] == remPlayerName){
            pos = i;
            break;
        }
    }
    cout << "Pos: " << pos << ", Current Pos: " << _curr_turn << endl;
    if (pos < _curr_turn){_curr_turn--;}
}

void Game::setPlayers(const vector<string>& players) {
    _players.clear();
    for(const string& player: players){_players.push_back(player);}
}




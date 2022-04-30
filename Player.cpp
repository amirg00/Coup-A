#include "Player.hpp"
using namespace coup;
using std::move; using std::runtime_error;

Player::Player(Game& game, string name, string role)
: _game(game), _name(move(name)), _role(move(role)), _coins(0), _coup(false), _coupBlock(false), _steal_coins(0),
_doubleIncomeBlock(false), _stealBlock(false), _curr_operation(State::UNINITIALIZED), _player_ptr(nullptr)
{
    _game.addPlayer(_name);
}

void Player::income() {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= LIMIT) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    increase(1);
    _game.next_turn();
}

void Player::foreign_aid() {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    if (_coins >= LIMIT) {throw runtime_error("ERR: player has 10 coins and didn't perform coup.");}
    /*Set current operation to be double income*/
    _curr_operation = State::FOREIGN_AID;
    increase(2);
    _game.next_turn();
}

void Player::coup(Player& target) {
    if (!isPlayerTurn()) {throw runtime_error("ERR: not player's turn!");}
    _players = _game.players();

    /*Player is assassin*/
    if (_role == "Assassin"){
        if (_coins >= COUP_CHARGE){ /*If he has 7 coins then coup is cost 7 coins*/
            coupByCoins(target, COUP_CHARGE);
            return;
        }
        if (_coins >= ASSASSIN_COUP_CHARGE){ /* If he doesn't have 7 coins but 3, then coup is cost 3 coins instead of 7*/
            coupByCoins(target, ASSASSIN_COUP_CHARGE);
            return;
        }
        /*Player doesn't have enough coins for the operation*/
        throw runtime_error("ERR: player doesn't have enough coins!");
    }
    /*Player isn't assassin*/
    if (_coins < COUP_CHARGE){  /*Player doesn't have enough coins for the operation*/
        throw runtime_error("ERR: player doesn't have enough coins!");
    }
    coupByCoins(target, COUP_CHARGE);
}

//Auxiliary method for the coup method.
void Player::coupByCoins(Player &target, int coins) {
    _curr_operation = State::COUP;
    decrease(coins);
    _game.fixCurrPos(target._name);
    _game.remPlayer(target._name);
    if (_game.players().size() == 1){ /* Check if player is the winner = last remained*/
        _game.setWinner(_name);
    }
    target.setCoup(true);
    target.setCoupPlayerName(_name);
    _game.next_turn();
}


int Player::coins() const {
    return _coins;
}

string Player::role() const {
    return _role;
}

string Player::name() const {
    return _name;
}

void Player::increase(int amount) {
    _coins+=amount;
}

void Player::decrease(int amount) {
    _coins-=amount;
}

bool Player::isPlayerTurn() {
    return _game.turn() == _name;
}

bool Player::isCoup() const {
    return _coup;
}

string Player::getCoupPlayerName() {
    return _coupPlayerName;
}

void Player::setCoup(bool coup) {
    _coup = coup;
}

void Player::setCoupPlayerName(const string& name) {
    _coupPlayerName = name;
}

bool Player::getDoubleIncomeBlock() const {
    return _doubleIncomeBlock;
}

bool Player::getStealBlock() const {
    return _stealBlock;
}

bool Player::getCoupBlock() const {
    return _coupBlock;
}

void Player::setDoubleIncomeBlock(bool b) {
    _doubleIncomeBlock = b;
}

void Player::setStealBlock(bool b) {
    _stealBlock = b;
}

void Player::setCoupBlock(bool b) {
    _coupBlock = b;
}

State Player::getCurrState() {
    return _curr_operation;
}

vector<string> Player::getPlayers() {
    return _players;
}

Player& Player::getPlayer_ptr() {
    return *_player_ptr;
}

int Player::getStealAmount() const {
    return _steal_coins;
}

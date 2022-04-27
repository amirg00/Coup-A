#include "Player.hpp"
using std::move;

Player::Player(Game& game, string name, string role)
: _game(game), _name(move(name)), _role(move(role)), _coins(0), _coup(false), _coupBlock(false),
_doubleIncomeBlock(false), _stealBlock(false), _curr_operation(State::UNINITIALIZED)
{
    _game.addPlayer(_name);
}

void Player::income() {
    if (!isPlayerTurn()) {throw std::exception();}
    increase(1);
    _game.next_turn();
}

void Player::foreign_aid() {
    if (!isPlayerTurn()) {throw std::exception();}

    /*Set current operation to be double income*/
    _curr_operation = State::FOREIGN_AID;

    increase(2);
    _game.next_turn();
}

void Player::coup(Player& target) {
    if (!isPlayerTurn()) {throw std::exception();}
    _players = _game.players();
    /*Player is assassin*/
    if (_role == "Assassin"){
        if (_coins >= 3){
            _curr_operation = State::COUP;
            decrease(3);
            _game.remPlayer(target._name);
            target.setCoup(true);
            target.setCoupPlayerName(_role);
            _game.next_turn();
            return;
        }
        else{ /*Player doesn't have enough coins for the operation*/
            throw std::exception();
        }
    }

    /*Player isn't assassin*/
    if (_coins < 7){  /*Player doesn't have enough coins for the operation*/
        throw std::exception();
    }
    _curr_operation = State::COUP;
    decrease(7);
    _game.remPlayer(target._name);
    target.setCoup(true);
    target.setCoupPlayerName(_role);
    _game.next_turn();
}

int Player::coins() const {
    return _coins;
}

string Player::role() const {
    return _role;
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



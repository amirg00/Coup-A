#pragma once
#include "Game.hpp"


enum class State{
    UNINITIALIZED,
    FOREIGN_AID,
    COUP,
    STEAL
};

class Player {
protected:
    Game& _game;              /* Game reference*/
    string _name;             /* Player's name*/
    string _role;             /* Player's role: Ambassador, Assassin, Captain, Contessa, or Duke */
    int _coins;               /* Player's total amount of coins */
    bool _coup;               /* Flag - indicates if player has been couped */
    string _coupPlayerName;   /* The player which has couped the current player if such exist */
    bool _doubleIncomeBlock;  /* Flag - indicates if player has been blocked for foreign_aid operation*/
    bool _stealBlock;         /* Flag - indicates if player has been blocked for steal operation*/
    bool _coupBlock;          /* Flag - indicates if player has been blocked for coup operation*/
    State _curr_operation;    /* States Player's latest operation, which can be blocked*/
    vector<string> _players;  /* Store previous order for players before coup is accomplished*/
public:
    Player(Game& game, string name, string role);
    void income();            /* Income = 1 coins */
    void foreign_aid();       /* Doubled income =  2 coins */
    void coup(Player& target);
    void coupByCoins(Player& target, int coins);
    int coins() const;
    string role() const;
    void increase(int amount);
    void decrease(int amount);
    bool isPlayerTurn();
    bool isCoup() const;
    string getCoupPlayerName();
    void setCoup(bool coup);
    void setCoupPlayerName(const string& name);
    bool getDoubleIncomeBlock() const;
    void setDoubleIncomeBlock(bool b);
    bool getStealBlock() const;
    void setStealBlock(bool b);
    bool getCoupBlock() const;
    void setCoupBlock(bool b);
    State getCurrState();
    vector<string> getPlayers();
};
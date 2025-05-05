#pragma once
#include"Player.h"
class Player {
protected:
    Board* ownBoard;
    Board* enemyBoard;
    string name;

public:
    Player(const string& name) : name(name) {
        ownBoard = new Board();
        enemyBoard = new Board();
    }

    virtual ~Player() {
        delete ownBoard;
        delete enemyBoard;
    }

    string getName() const { return name; }
    Board* getOwnBoard() const { return ownBoard; }
    Board* getEnemyBoard() const { return enemyBoard; }
    void setOwnBoard(Board* board) {
        ownBoard = board;
    }
    void setEnemyBoard(Board* board) {
        enemyBoard = board;
    }
    virtual bool isBot() const { return false; }
};
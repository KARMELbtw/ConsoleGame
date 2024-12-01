#ifndef UNTITLED1_PLAYER_H
#define UNTITLED1_PLAYER_H

#include <iostream>
#include <vector>
#include "../Enums/Difficulty.cpp"
#include "Enemy.h"

using namespace std;

class Enemy;

class Player {
public:
    Player(int hp, const string &name, int damage);

    bool alive = true;
    int hp;
    string name;
    int damage;

    bool attack(Enemy& enemy);
    void takeDamage(int damage);
};


#endif

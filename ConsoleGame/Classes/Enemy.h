#ifndef UNTITLED1_ENEMY_H
#define UNTITLED1_ENEMY_H

#include <iostream>

#include "Player.h"
#include "Math.h"

using namespace std;

class Player;

class Enemy {
public:
    Enemy(int hp, int damage);

    int hp;
    string name;
    int damage;
    vector<string> names = {"John", "Doe", "Jane", "Smith", "Alice", "Bob", "Eve", "Mallory", "Trudy", "Carol",
                                   "Dave", "Frank", "Grace", "Heidi", "Ivan", "Judy", "Mallory", "Oscar", "Peggy",
                                   "Romeo", "Sybil", "Trent", "Victor", "Walter", "Wendy", "Zoe", "Charlie", "David",
                                   "Edward", "George", "Harry", "Tom", "Jerry", "Mickey", "Minnie", "Donald", "Daisy",
                                   "Goofy", "Pluto", "Chip", "Dale", "Scrooge", "Huey", "Dewey", "Louie", "Webby",
                                   "Launchpad", "Gyro", "Fenton", "Gizmoduck", "Darkwing", "Gosalyn", "Megavolt", "Negaduck"};

    bool attack(Player& player, int d);
    void takeDamage(int damage);
};



#endif


#include "Enemy.h"

#define RESET           "\033[0m"
#define RED             "\033[31m"
#define GREEN           "\u001b[32m"
#define BACKGROUNDGREEN  "\u001b[42m"
#define YELLOW          "\u001b[33m"
#define BLUE            "\u001b[34m"

Enemy::Enemy(int hp, int damage) {
    this->hp = hp;
    this->name = this->names[Math::random(0, this->names.size())];
    this->damage = damage;
}

bool Enemy::attack(Player& player, int d) {
    int dmg = Math::random(this->damage, this->damage+d);
    player.takeDamage(dmg);
    cout << "You took " << RED << dmg << RESET << " damage" << endl;
    if (player.hp <= 0) {
        cout << RED << "You died!" << RESET << endl;
        return true;
    } else {
        return false;
    }
}

void Enemy::takeDamage(int damage) {
    this->hp -= damage;
}

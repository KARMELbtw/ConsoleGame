
#include "Player.h"

#define RESET           "\033[0m"
#define RED             "\033[31m"
#define GREEN           "\u001b[32m"
#define BACKGROUNDGREEN  "\u001b[42m"
#define YELLOW          "\u001b[33m"
#define BLUE            "\u001b[34m"

Player::Player(int hp, const string &name, int damage) {
    this->hp = hp;
    this->name = name;
    this->damage = damage;
}

bool Player::attack(Enemy& enemy) {
    int dmg = Math::random(this->damage, this->damage+2);
    enemy.takeDamage(dmg);
    cout << "You dealt " << GREEN << dmg << RESET << " damage to " << enemy.name << endl;
    if (enemy.hp <= 0) {
    cout << GREEN << "You killed the enemy!" << RESET << endl;
        return true;
    } else {
        return false;
    }
}

void Player::takeDamage(int damage) {
    this->hp -= damage;
}

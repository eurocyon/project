#include "player.h"

Player::Player(int z) : hp(z) {
    setHealth(z);
};
void Player::setHealth(int x) {
    hp = x;
};
int Player::getHealth() const {
    return hp;
};


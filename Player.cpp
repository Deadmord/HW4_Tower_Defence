#include "Player.h"

//------------------Player-Body----------------------
int Player::nextID = 0;

Player::Player(std::string fraction_id, std::string name) :fraction_id(fraction_id), name(name) { id = std::to_string(++nextID); };

Player::Player(const Player& orig) :name(orig.name), fraction_id(orig.fraction_id) { id = std::to_string(++nextID); } //проверить логику, что присваивать id

Player& Player::operator=(const Player& orig) { name = orig.name; fraction_id = orig.fraction_id, id = std::to_string(++nextID); return(*this); } //проверить логику, что присваивать id

void Player::ChangeName(std::string NewName) { name = NewName; }

void Player::ChangeFraction(std::string NewFractionID) { name = NewFractionID; }
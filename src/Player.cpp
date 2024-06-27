#include "Player.h"

#include <string>

Player::Player() {
	
}

void Player::setName(char* playerName) {
	name = std::string(playerName);
}

std::string Player::getName() {
	return name;
}

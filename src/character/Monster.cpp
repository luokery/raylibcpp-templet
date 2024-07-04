#include "Monster.h"

Monster::Monster() {
	
}

void Monster::setName(char* monster_name) {
	name = std::string(monster_name);
}

std::string Monster::getName() {
	return name;
}

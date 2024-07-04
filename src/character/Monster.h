
#ifndef monster_h
#define monster_h

#include <string>

class Monster {
	public:
		Monster();
	
		void setName(char *name);

		std::string getName();

	private:
		std::string name;
		int age;

		int hp;
		int mp;


};

#endif

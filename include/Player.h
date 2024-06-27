#ifndef player_h
#define player_h

#include <string>

//namespace Player {
class Player {
	public:
		Player();
	
		void setName(char *name);

		std::string getName();

	private:
		std::string name;
		int age;

		int hp;
		int mp;


};
//}  // namespace Player

#endif

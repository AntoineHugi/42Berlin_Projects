#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMAN_B_H
# define HUMAN_B_H

class HumanB {

	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif
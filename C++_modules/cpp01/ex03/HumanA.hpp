#include <iostream>
#include <string>
#include "Weapon.hpp"

#ifndef HUMAN_A_H
# define HUMAN_A_H

class HumanA {

	private:
		std::string _name;
		Weapon _weapon;
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);
		void	attack();
};

#endif
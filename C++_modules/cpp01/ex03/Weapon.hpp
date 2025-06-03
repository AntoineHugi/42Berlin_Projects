#include <iostream>
#include <string>

#ifndef WEAPON_H
# define WEAPON_H

class Weapon {

	private:
		std::string _type;

	public:
		Weapon(std::string name);
		~Weapon(void);
		const std::string&	getType();
		void			setType(std::string type);
};

#endif
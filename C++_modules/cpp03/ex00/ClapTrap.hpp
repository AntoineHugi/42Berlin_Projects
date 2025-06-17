#include <iostream>
#include <string>

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

class ClapTrap 
{
    private:
        std::string 	_name;
        unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_dmg;

    public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
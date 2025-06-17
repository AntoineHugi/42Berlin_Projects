#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_name(""), _hp(10), _ep(10), _dmg(0)
{
	return ;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << this->_name << " beeps to life." << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " has been destroyed." << std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep > 0)
	{
		this->_ep--;
		std::cout << this->_name << " attacked " << target << " and inflicted " << this->_dmg << " dmg (!)" << std::endl;
	}
	else
	{
		std::cout << this->_name << " does not have enough energy points for this action." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp - amount > 0)
	{
		this->_hp -= amount;
		std::cout << this->_name << " took " << amount << " damage and now has " << this->_hp << " hp left." << std::endl;
	}
	else
	{
		this->_hp = 0;
		std::cout << this->_name << " took " << amount << " damage and died." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_ep > 0)
	{
		this->_ep--;
		this->_hp += amount;
		std::cout << this->_name << " healed itself by " << amount << " and now has " << this->_hp << " hp left." << std::endl;
	}
	else
	{
		std::cout << this->_name << " does not have enough energy points for this action." << std::endl;
	}
}
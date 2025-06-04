#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name), _weapon(NULL)
{
	return ;
}
HumanB::~HumanB(void)
{
	return ;
}
void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "!" << std::endl;
	else
		std::cout << this->_name << " attacks with their fists!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
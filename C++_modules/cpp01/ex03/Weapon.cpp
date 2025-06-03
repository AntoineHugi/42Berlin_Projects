#include "Weapon.hpp"

Weapon::Weapon(std::string name):_type(name){
	return ;
}

Weapon::~Weapon(void){
	return ;
}

const std::string& Weapon::getType()
{
	std::string &type = this->_type;
	return (type);
}
void	Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}
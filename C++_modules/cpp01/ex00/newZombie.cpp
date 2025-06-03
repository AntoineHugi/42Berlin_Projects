#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *newguy = new Zombie(name);
	return (newguy);
}
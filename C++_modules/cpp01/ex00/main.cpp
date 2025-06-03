#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *one;
	one = newZombie("Frank");
	one->announce();
	delete one;
	randomChump("Mark");
}
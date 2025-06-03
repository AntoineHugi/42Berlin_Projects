#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	Zombie *horde;
	int N = 4;

	horde = zombieHorde(N, "Alfred");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
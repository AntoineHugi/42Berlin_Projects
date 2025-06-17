#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap robocop("Robocop");

	robocop.attack("a wall");
	robocop.takeDamage(5);
	robocop.beRepaired(3);
}
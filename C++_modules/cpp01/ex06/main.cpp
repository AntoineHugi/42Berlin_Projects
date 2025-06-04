#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	typical_harl;

	if (argc != 2)
	{
		std::cout << "only one argument please, Harl's level of complaint" << std::endl;
		return (1);
	}
	std::string level = argv[1];
	typical_harl.complain(level);
	return (0);
}
#include "Harl.hpp"

int main()
{
	Harl	typical_harl;
	typical_harl.complain("DEBUG");
	typical_harl.complain("INFO");
	typical_harl.complain("WARNING");
	typical_harl.complain("ERROR");
	typical_harl.complain("other");

	return (0);
}
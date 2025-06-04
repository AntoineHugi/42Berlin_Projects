#include "Harl.hpp"

void	Harl::_debug()
{
	std::cout << "DEBUG" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl << std::endl;
}

void	Harl::_info()
{
	std::cout << "INFO" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger!" << std::endl << "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void	Harl::_warning()
{
	std::cout << "WARNING" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::_error()
{
	std::cout << "ERROR" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			index = i;
	}
	switch (index)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems. ]" << std::endl;
	}
}

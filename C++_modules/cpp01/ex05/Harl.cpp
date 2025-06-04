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
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
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
	typedef	void(Harl::*fun_ptr)(void);
	
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	fun_ptr		complaints[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems. ]" << std::endl;
}
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
	_index(-1)
	{
		return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool	PhoneBook::_is_alpha(std::string input)
{
	if (input.empty())
		return (false);
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isalpha(*i) && *i != ' ' && *i != '-')
			return (false);
	}
	return (true);
}

bool	PhoneBook::_is_digits(std::string input)
{
	if (input.empty())
		return (false);
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isdigit(*i))
			return (false);
	}
	return (true);
}

void	PhoneBook::_increase_index()
{
	_index++;
	if (_index > 7)
		_index = 0;
	return ;
}

bool	PhoneBook::_index_found(std::string input)
{
	int		selection;
	std::stringstream sstream(input);

	if (input.empty())
		return (false);
	if (!_is_digits(input))
		return (false);
	sstream >> selection;
	if (selection >= 0 && selection <= this->_index)
		return (true);
	else
		return (false);
}

void	PhoneBook::_diplay_contact(int index)
{
	std::cout << "First name: " << this->_Contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_Contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_Contacts[index].get_nickname() << std::endl;
	std::cout << "Number: " << this->_Contacts[index].get_number() << std::endl;
	std::cout << "Secret: " << this->_Contacts[index].get_secret() << std::endl;
}

std::string PhoneBook::_trim_data(std::string input)
{
	std::string	replace;

	if (input.length() <= 10)
		return (input);
	else
	{
		replace = input.substr(0, 9) + ".";
		return (replace);
	}
}

void	PhoneBook::add_contact(void)
{
	std::string input;
	
	this->_increase_index();
	std::cout << "---- Add contact menu ----" << std::endl;
	std::cout << "---- Please provide a first name ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Error ----" << std::endl << "---- Please use only alphabetical letters or spaces or hyphens. ----" << std::endl;
	this->_Contacts[_index].set_first_name(input);
	std::cout << "---- Please provide a last name ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Error ----" << std::endl << "---- Please use only alphabetical letters or spaces or hyphens. ----" << std::endl;
	this->_Contacts[_index].set_last_name(input);
	std::cout << "---- Please provide a nickname ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Error ----" << std::endl << "---- Please use only alphabetical letters or spaces or hyphens. ----" << std::endl;
	this->_Contacts[_index].set_nickname(input);
	std::cout << "---- Please provide a number ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_digits(input))
		std::cout << "---- Error ----" << std::endl << "---- Please use only numbers. ----" << std::endl;
	this->_Contacts[_index].set_number(input);
	std::cout << "---- Please provide a secret ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Error ----" << std::endl << "---- Please use only alphabetical letters or spaces or hyphens. ----" << std::endl;
	this->_Contacts[_index].set_secret(input);
	std::cout << "---- Contact successfully added. ----" << std::endl << std::endl;
}

void	PhoneBook::search_contacts(void)
{
	std::string input;
	int			selection;

	if (this->_index == -1)
	{
		std::cout << "---- There are no contacts right now, add some using the add command in the main menu. ----" << std::endl << std::endl;
		return ;
	}
	for (int i = 0; i < this->_index + 1; i++)
	{
		std::cout << i << " | " << this->_trim_data(_Contacts[i].get_first_name()) << " | " << this->_trim_data(_Contacts[i].get_last_name()) << " | " << this->_trim_data(_Contacts[i].get_nickname()) << std::endl;
	}
	std::cout << "---- Please provide the index of the contact you wish to see ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_index_found(input))
		std::cout << "---- Error ----" << std::endl << "---- Please provide the index of the contact you wish to see ----" << std::endl;
	std::stringstream sstream(input);
	sstream >> selection;
	this->_diplay_contact(selection);
}
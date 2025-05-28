#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
	_index(-1)
	//,_cancel(false)
	{
		return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}


bool	PhoneBook::_is_alpha(std::string input)
{
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isalpha(*i) && *i != ' ' && *i != '-')
			return (false);
	}
	return (true);
}

bool	PhoneBook::_is_digits(std::string input)
{
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isdigit(*i))
			return (false);
	}
	return (true);
}

void	PhoneBook::_get_index()
{
	_index++;
	if (_index > 7)
		_index = 0;
	return ;
}
void	PhoneBook::_reset_contact(void)
{
	this->_Contacts[_index].set_first_name("");
	this->_Contacts[_index].set_last_name("");
	this->_Contacts[_index].set_nickname("");
	this->_Contacts[_index].set_number("");
	this->_Contacts[_index].set_secret("");
}

void	PhoneBook::add_contact(void)
{
	std::string input;
	
	PhoneBook::_get_index();
	std::cout << "---- Add contact menu ----" << std::endl;
	std::cout << "---- Please provide a first name ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Please use only alphabetical letters or spaces or hyphens ----" << std::endl;
	this->_Contacts[_index].set_first_name(input);
	std::cout << "---- Please provide a last name ----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Please use only alphabetical letters or spaces or hyphens ----" << std::endl;
	this->_Contacts[_index].set_last_name(input);
	std::cout << "----Please provide a nickname----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Please use only alphabetical letters or spaces or hyphens ----" << std::endl;
	this->_Contacts[_index].set_nickname(input);
	std::cout << "----Please provide a number----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_digits(input))
		std::cout << "---- Please use only numbers ----" << std::endl;
	this->_Contacts[_index].set_number(input);
	std::cout << "----Please provide a secret----" << std::endl;
	while (!std::getline(std::cin, input) || std::cin.eof() || !_is_alpha(input))
		std::cout << "---- Please use only alphabetical letters or spaces or hyphens ----" << std::endl;
	this->_Contacts[_index].set_secret(input);
}

void	PhoneBook::search_contacts(void)
{
	return ;
}

void	PhoneBook::exit_app(void)
{
	std::cout << "---- THANK YOU FOR USING PHONEBOOK3000 ----" << std::endl;
}
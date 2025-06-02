#include "Contacts.hpp"

Contact::Contact(void):
	_first_name(""),
	_last_name(""),
	_nickname(""),
	_number(""),
	_secret("") 
	{
		return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_first_name()
{
	return (this->_first_name);
}

std::string	Contact::get_last_name()
{
	return (this->_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->_nickname);
}

std::string	Contact::get_number()
{
	return (this->_number);
}

std::string	Contact::get_secret()
{
	return (this->_secret);
}

void	Contact::set_first_name(std::string input)
{
	Contact::_first_name = input;
}

void	Contact::set_last_name(std::string input)
{
	Contact::_last_name = input;
}

void	Contact::set_nickname(std::string input)
{
	Contact::_nickname = input;
}

void	Contact::set_number(std::string input)
{
	Contact::_number = input;
}

void	Contact::set_secret(std::string input)
{
	Contact::_secret = input;
}
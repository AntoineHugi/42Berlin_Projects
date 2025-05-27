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

Contact::~Contact(void){
	return ;
}

bool	Contact::_is_alpha(std::string input)
{
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isalpha(*i))
			return (false);
	}
	return (true);
}

bool	Contact::_is_digit(std::string input)
{
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if(!std::isdigit(*i))
			return (false);
	}
	return (true);
}
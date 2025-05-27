#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
	_index(-1),
	_cancel(false)
	{
		return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void	PhoneBook::_get_index(){
	_index++;
	if (_index > 7)
		_index = 0;
	return ;
}

bool	PhoneBook::add_contact(void){
	PhoneBook::_get_index();

}

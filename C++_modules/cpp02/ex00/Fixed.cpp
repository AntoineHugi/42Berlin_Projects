#include "Fixed.hpp"

Fixed::Fixed():_fpnum(0)
{
	return ;
}

Fixed::Fixed(const Fixed& other):_fpnum(other._fpnum)
{
	return ;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_fpnum = other._fpnum;
	}
}

Fixed::~Fixed()
{
	return ;
}
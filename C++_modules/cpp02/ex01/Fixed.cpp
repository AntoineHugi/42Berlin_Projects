#include "Fixed.hpp"

Fixed::Fixed():_fpnum(0)
{
	std::cout << "Default constuctor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
	return ;
}

Fixed::Fixed(const int value):_fpnum(value << _nbits)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fpnum = (int)roundf(value * (1 << _nbits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fpnum = other._fpnum;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpnum);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpnum = raw;
	return ; 
}

float	Fixed::toFloat( void ) const
{
	return ((float)_fpnum / (1 << _nbits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fpnum >> this->_nbits);
}

std::ostream& operator<<(std::ostream& outStream, const Fixed& fixedNum)
{
	outStream << fixedNum.toFloat();
	return (outStream);
}

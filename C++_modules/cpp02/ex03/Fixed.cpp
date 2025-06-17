#include "Fixed.hpp"

/**** Constructors ****/

Fixed::Fixed():_fpnum(0)
{
	//std::cout << "Default constuctor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
	return ;
}

Fixed::Fixed(const int value):_fpnum(value << _nbits)
{
	//std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	_fpnum = (int)roundf(value * (1 << _nbits));
}
/**** Destructor ****/

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

/**** Overload operators ****/

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fpnum = other._fpnum;
	}
	return (*this);
}

bool Fixed::operator<(const Fixed& other)
{
	if (this->_fpnum < other._fpnum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>(const Fixed& other)
{
	if (this->_fpnum > other._fpnum)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& other)
{
	if (this->_fpnum <= other._fpnum)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& other)
{
	if (this->_fpnum >= other._fpnum)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& other)
{
	if (this->_fpnum == other._fpnum)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& other)
{
	if (this->_fpnum != other._fpnum)
		return (true);
	else
		return (false);
}

Fixed& Fixed::operator+(const Fixed& other)
{
	this->_fpnum = (int)roundf((this->toFloat() + other.toFloat()) * (1 << _nbits));
	return (*this);
}

Fixed& Fixed::operator-(const Fixed& other)
{
	this->_fpnum = (int)roundf((this->toFloat() - other.toFloat()) * (1 << _nbits));
	return (*this);
}

Fixed& Fixed::operator*(const Fixed& other)
{
	this->_fpnum = (int)roundf((this->toFloat() * other.toFloat()) * (1 << _nbits));
	return (*this);
}

Fixed& Fixed::operator/(const Fixed& other)
{
	this->_fpnum = (int)roundf((this->toFloat() / other.toFloat()) * (1 << _nbits));
	return (*this);
}

Fixed& Fixed::operator++()
{
	this->_fpnum += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->_fpnum += 1;
	return (temp);
}
Fixed& Fixed::operator--()
{
	this->_fpnum -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
		Fixed	temp = *this;
	
		this->_fpnum -= 1;
		return (temp);
}

/**** min-max ****/

	Fixed& Fixed::min(Fixed& a, Fixed& b)
	{
		if (a.getRawBits() < b.getRawBits())
			return (a);
		else
			return (b);
	}

	Fixed& Fixed::max(Fixed& a, Fixed& b)
	{
		if (a.getRawBits() < b.getRawBits())
			return (b);
		else
			return (a);
	}

	const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
	{
		if (a.getRawBits() < b.getRawBits())
			return (a);
		else
			return (b);
	}

	const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
	{
		if (a.getRawBits() < b.getRawBits())
			return (b);
		else
			return (a);
	}

/**** Public Functions ****/

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpnum);
}

void	Fixed::setRawBits(const int raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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

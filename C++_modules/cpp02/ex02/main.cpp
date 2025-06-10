#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "at the start value of A is: " << a << std::endl;
	std::cout << "pre-incrementing A with the smallest possible value: " << ++a << std::endl;
	std::cout << "A's value has been changed to: " << a << std::endl;
	std::cout << "post-incrementing gives us: " << a++ << std::endl;
	std::cout << "although the new value of A is: " << a << std::endl;
	std::cout << "pre-decrementing A is: " << --a << std::endl;
	std::cout << "B's value is: " << b << std::endl;
	std::cout << "max between A and B is: " << Fixed::max(a, b) << std::endl;
	std::cout << "A + B is: " << a + b << std::endl;
	return 0;
}
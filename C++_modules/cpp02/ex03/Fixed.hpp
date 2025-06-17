#include <iostream>
#include <cmath>

#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int	_fpnum;
		static const int	_nbits = 8;

	public:

	/**** Constructors ****/
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);

	/**** Destructor ****/
		~Fixed();

	/**** Overload operators ****/
		Fixed& operator=(const Fixed& other);
		Fixed& operator+(const Fixed& other);
		Fixed& operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		Fixed& operator/(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

	/**** min-max ****/
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

	/**** Public Functions ****/
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream& operator<<( std::ostream & os, const Fixed & number );

#endif
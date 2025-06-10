#include <iostream>
#include <cmath>

#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int	_fpnum;
		static const int	_nbits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream & operator<<( std::ostream & os, const Fixed & number );

#endif
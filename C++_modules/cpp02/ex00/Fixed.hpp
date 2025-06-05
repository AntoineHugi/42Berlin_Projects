#include <iostream>

#ifndef FIXED_H
# define FIXED_H

class Fixed {

	private:
		int	_fpnum;
		static const int	_nbits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
#include <iostream>
#include <string>


#ifndef HARL_H
# define HARL_H


class Harl {

	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif
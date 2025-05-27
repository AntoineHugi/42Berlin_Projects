#include <iostream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

class	PhoneBook {
	private:
		Contact _Contacts[8];
		int		_index;
		bool		_cancel;
		int		_is_digits(std::string input);
		int		_is_alpha(std::string input);
		void		_get_index(void);

	public:
		bool	add_contact();
		void	search_contacts();
		void	exit();
};
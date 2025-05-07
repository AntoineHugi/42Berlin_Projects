#include <iostream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

class	PhoneBook {
	private:
		Contact _Contacts[8];
		int		_is_digits(std::string input);
		int		_is_alpha(std::string input);

	public:
		void	add_contact();
		void	search_contacts();
		void	exit();
}
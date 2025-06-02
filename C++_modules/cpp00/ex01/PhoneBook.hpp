#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "Contacts.hpp"

class	PhoneBook {
	private:
		Contact		_Contacts[8];
		int			_index;
		bool		_is_digits(std::string input);
		bool		_is_alpha(std::string input);
		void		_increase_index(void);
		bool		_index_found(std::string input);
		void		_diplay_contact(int index);
		std::string	_trim_data(std::string input);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact();
		void	search_contacts();
};
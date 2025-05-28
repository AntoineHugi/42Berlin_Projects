#include <iostream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

class	PhoneBook {
	private:
		Contact _Contacts[8];
		int		_index;
		//bool		_cancel;
		bool		_is_digits(std::string input);
		bool		_is_alpha(std::string input);
		void		_get_index(void);
		void		_reset_contact(void);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact();
		void	search_contacts();
		void	exit_app();
};
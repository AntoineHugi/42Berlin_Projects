#include <iostream>
#include <string>
#include <cctype> 

class Contact {
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _number;
		std::string _secret;
		bool	_is_alpha(std::string input);
		bool	_is_digit(std::string input);

	public:
		Contact(void);
		~Contact(void);

		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname_name();
		std::string	get_number();
		std::string	get_secret();

		void		set_first_name(std::string input);
		void		set_last_name(std::string input);
		void		set_nickname_name(std::string input);
		void		set_number(std::string input);
		void		set_secret(std::string input);
};
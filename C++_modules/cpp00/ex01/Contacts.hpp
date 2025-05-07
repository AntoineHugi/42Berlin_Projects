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

	public:
		Contact(void);
		~Contact(void);
};
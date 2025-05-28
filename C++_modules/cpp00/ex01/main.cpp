#include "PhoneBook.hpp"

bool	wrong_command(std::string input)
{
	if (input == "ADD" || input == "SEARCH" || input == "EXIT")
		return (false);
	else if (input == "add" || input == "search" || input == "exit")
		return (false);
	else
		return (true);
}

int main ()
{
	std::string	input;
	PhoneBook	pb;
	
	std::cout << "---- WELCOME TO THE PHONEBOOK3000 TECHNOLOGY ----" << std::endl;
	while (true)
	{
		std::cout << "---- PLEASE TYPE A COMMANMD: ADD / SEARCH / EXIT ----" << std::endl;
		while (!std::getline(std::cin, input) || std::cin.eof() || wrong_command(input))
			std::cout << "---- PLEASE TYPE A COMMANMD: ADD / SEARCH / EXIT ----" << std::endl;
		if (input == "ADD" || input == "add")
			pb.add_contact();
		if (input == "SEARCH" || input == "search")
			pb.search_contacts();
		if (input == "EXIT" || input == "exit")
			break ;
	}
	std::cout << "---- THANK YOU FOR USING PHONEBOOK3000 ----" << std::endl;
}
#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "the memory address of str is: " << &str << std::endl;
	std::cout << "the memory address of ptr str is: " << stringPTR << std::endl;
	std::cout << "the memory address of ref str is: " << &stringREF << std::endl;

	std::cout << "the value of str is: " << str << std::endl;
	std::cout << "the value of ptr str is: " << *stringPTR << std::endl;
	std::cout << "the value of ref str is: " << stringREF << std::endl;
}
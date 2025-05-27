#include <iostream>
#include <string>
#include <cctype> 

std::string	concat_args(int argc, char **argv)
{
	std::string input = argv[1];

	for (int i = 2; i < argc; i++)
		input += argv[i];
	return (input);
}

int	main(int argc, char **argv)
{
	std::string input;

	if (argc < 2)
		input = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		input = concat_args(argc, argv);
	for (std::string::size_type i = 0; i < input.length(); i++)
		input[i] = std::toupper(static_cast<unsigned char>(input[i]));
	std::cout << input << std::endl;
	return 0;
}

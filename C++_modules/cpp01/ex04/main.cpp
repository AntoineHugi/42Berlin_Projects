#include <iostream>
#include <string>
#include <fstream>

int	print_error()
{
	std::cout << "please provide 3 arguments: an existing filename, a string to be replaced, and the replacement." << std::endl;
	return (1);
}

std::string	replace_sequence(std::string line, std::string sequence, std::string replacement)
{
	std::string	newline;
	
	newline = line.substr(0, line.find(sequence));
	if (newline.length() < line.length())
	{
		newline.append(replacement);
		newline.append(line.substr(line.find(sequence) + sequence.length()));
	}
	return (newline);
}

std::string	create_outputname(std::string input)
{
	std::string outputname;
	
	if (input.length() >= 4 && input.substr(input.length() - 4) == ".txt")
		outputname = input.substr(0, input.length() - 4) + ".replace.txt";
	else
		outputname = input + ".replace.txt";
	return (outputname);
}

int main(int argc, char **argv)
{
	std::string line;

	if (argc != 4)
		return (print_error());
	std::string filename = argv[1];
	if (filename.empty())
		return (print_error());
	std::string outputname = create_outputname(filename);
	std::string sequence = argv[2];
	std::string replacement = argv[3];
	std::ifstream file(filename.c_str());
	if (file.is_open())
	{
		std::ofstream output(outputname.c_str());
		if (output.is_open())
		{
			while (std::getline(file, line))
			{
				line = replace_sequence(line, sequence, replacement);
				output << line << std::endl;
			}
			output.close();
		}
		else
		{
			std::cout << "error creating replacement file." << std::endl;
			file.close();
			return (1);
		}
		file.close();
	}
	else
		return (print_error());
	return (0);
}
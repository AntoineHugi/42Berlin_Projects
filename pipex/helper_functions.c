#include "pipex.h"

void	print_error(char *msg)
{
	int	i;

	write(2, "Error\n", 7);
	i = 0; 
	while (msg[i])
	{
		write(2, &msg[i], 1);
	}
	write(2, "\n", 1);
	exit(1);
}

int	input_validation(int argc)
{
	if (argc != 5)
		print_error("Provide 4 arguments: infile cmd1 cmd2 outfile");
	//if (!access(argv[1], R_OK) || !access(argv[4], W_OK))
	//	print_error("one or both files don't exist.");
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:48:02 by ahugi             #+#    #+#             */
/*   Updated: 2025/02/17 14:48:04 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(char *msg)
{
	int	i;

	write(2, "Error\n", 7);
	i = 0; 
	while (msg[i])
		write(2, &msg[i++], 1);
	write(2, "\n", 1);
	exit(1);
}

int	input_validation(int argc)
{
	if (argc != 5)
		print_error("Provide 4 arguments: infile cmd1 cmd2 outfile");
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

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

void	print_error(char *msg, int err_num)
{
	int	i;

	i = 0;
	while (msg[i])
		write(2, &msg[i++], 1);
	if (err_num == 127)
		write(2, ": command not found", 20);
	if (err_num == 2)
		write(2, ": No such file or directory", 28);
	write(2, "\n", 1);
	exit (err_num);
}

int	input_validation(int argc)
{
	if (argc != 5)
		print_error("invalid input", EXIT_FAILURE);
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

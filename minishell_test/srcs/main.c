/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:26:35 by ahugi             #+#    #+#             */
/*   Updated: 2025/03/03 15:19:15 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void disable_canon() 
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void enable_canon()
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;

	disable_canon();
	input = readline("Minishell $ ");
	while (input)
	{
		free(input);
		input = readline("Minishell $ ");
	}

	/* this part exits, when pressing ctrl-D*/
	if (feof(stdin)) {
		free(input);
		enable_canon();
		exit(0);
		return 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:00:15 by ahugi             #+#    #+#             */
/*   Updated: 2024/12/17 12:00:17 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_no_dup (char **args)
{
	int	i;
	int	j;
	int	check;

	check = 1;
	i = 0;
	while (args[i])
	{
		j = i + 1;
		while(args[j])
		{
			if (args[i] == args[j])
				check = 0;
			j++;
		}
		i++;
	}
	return (check);
}

int	ft_is_valid (char **args)
{
	int	i;
	int	j;
	int	check;

	check = 1;
	i = 0;
	while (args[i])
	{
		j = 0;
		while(args[i][j])
		{
			if (args[i][j] = '-')
				j++;
			if (!ft_is_digit(args[i][j]))
				check = 0;
			j++;
		}
		i++;
	}
	return (check);
}

int	main(int argc, char **argv)
{
    char    **args;

	if (argc == 1)
		return;
	if (argc == 2)
		args = ft_split(argv, ' ');
	if (argc > 2)
		args = argv;
	if (!ft_is_valid(args) || !ft_no_dup(args))
		write(2, "Error", 5);
	else
		ft_solve(args);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:17:43 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 14:19:10 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int		fd;
	int		counter;
	char 	*result;

	fd = open("./testfile.txt", O_RDWR);
	result = get_next_line(fd);
	counter = 0;
	while (result)
	{
		counter++;
		printf("\ncall #%i\n", counter);
		write(1, result, ft_strlen(result));
		free(result);
		result = get_next_line(fd);
	}
	free(result);
	return (0);
}

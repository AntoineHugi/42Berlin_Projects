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
#include <sys/stat.h>
#include <fcntl.h>

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != 0)
	{
		length++;
	}
	return (length);
}

int	main()
{
	int		fd;
	char 	*result;

	result = "";
	fd = open("./testfile.txt", O_RDWR);
	while (result)
	{
		result = get_next_line(fd);
		if (result)
		{
			write(1, result, ft_strlen(result));
		}
	}
	free(result);
	return (0);
}

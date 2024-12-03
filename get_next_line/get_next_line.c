/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:50:51 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 13:51:29 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_line(char *str)
{
	int		count;
	int		i;
	char	*line;

	if (!str)
		return (NULL);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	line = (char *)ft_calloc(count + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < count)
	{
		line[i] = str[i];
		i++;
	}
	if (str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

static int	check_if_n(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_file_to_buffer(int fd, char *result)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	if (!result)
		result = (char *)ft_calloc(1, 1);
	if (!result)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
	{
		free(result);
		free(buffer);
		return(NULL);
	}	
	while (bytes_read > 0)
	{
		if (!check_if_n(buffer))
		{
			result = ft_strjoin(&result, &buffer);
			if (!result)
				return (NULL);
		}
		else
		{
			result = ft_strjoin(&result, &buffer);
			break ;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (result && check_if_n(result))
	{
		line = create_line(result);
		result = ft_strchr_mod(&result);
		return (line);
	}
	result = read_file_to_buffer(fd, result);
	if (!result)
		return (NULL);
	line = create_line(result);
	result = ft_strchr_mod(&result);
	return (line);
}

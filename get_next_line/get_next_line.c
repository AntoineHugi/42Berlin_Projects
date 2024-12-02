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
	line = (char *)ft_calloc(sizeof(char), count + 2);
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
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*read_file_to_buffer(int fd, char *result)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!result)
		result = (char *)ft_calloc(1, 1);
	buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(result);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!check_if_n(buffer))
		{
			temp = result;
			result = ft_strjoin(result, buffer);
			if (!result)
			{
    				free(temp);
   				free(buffer);
   				return (NULL);
			}
			free(temp);
		}
		else
			break ;
	}
	temp = result;
	result = ft_strjoin(result, buffer);
	if (!result)
	{
    		free(temp);
   		free(buffer);
   		return (NULL);
	}
	free(temp);
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;
	char		*temp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (result)
	{
		if (check_if_n(result))
		{
			line = create_line(result);
			temp = result;
			result = ft_strchr_mod(result);
			free(temp);
			return (line);
		}
	}
	result = read_file_to_buffer(fd, result);
	if (!result || !*result)
	{
		free(result);
   		return (NULL);
	}
	line = create_line(result);
	temp = result;
	result = ft_strchr_mod(result);
	free(temp);
	if (!ft_strlen(line))
	{
		if (result)
			free(result);
		free(line);
		return (NULL);
	}
	return (line);
}

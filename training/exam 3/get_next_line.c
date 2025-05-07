#include "main.h"

void	ft_memcpy(char *dest, char *src, size_t n)
{
	size_t i = 0;

	if (!src)
		return ;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

size_t	ft_strlen(char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_result;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!new_result)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_memcpy(new_result, s1, s1_len);
	ft_memcpy(new_result + s1_len, s2, s2_len);
	new_result[s1_len + s2_len] = '\0';
	free(s1);
	s1 = new_result;
	return (s1);
}

char	*reduce_result(char *result)
{
	int i = 0;
	char	*new_result;
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		i++;
	new_result = (char *)malloc(sizeof(char) * (ft_strlen(result + i) + 1));
	if (!new_result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	ft_memcpy(new_result, result + i, ft_strlen(result + i));
	new_result[ft_strlen(result + i)] = '\0';
	free(result);
	result = new_result;
	return (result);
}

char	*create_line(char *result)
{
	int i = 0;
	char	*line;

	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, result, i);
	line[i] = '\0';
	return (line);
}

int		check_n(char *str)
{
	int	i = 0;

	if (!str)
		return (0);	
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(char *result, int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
		if (!result || check_n(result))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || (result && !ft_strlen(result)))
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*line;

	if (!result)
		result = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	if (result && check_n(result))
	{
		line = create_line(result);
		result = reduce_result(result);
		return (line);
	}
	result = read_file(result, fd);
	if (!result)
		return (NULL);
	line = create_line(result);
	result = reduce_result(result);
	return (line);
}

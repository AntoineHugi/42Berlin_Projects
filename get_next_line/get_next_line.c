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

static char	*read_file_to_buffer(int fd, char *result)
{
    char    *buffer;
    ssize_t bytes_read;

    //in case we have nothing at first, making a quick calloc so result is not null
    if (!result)
        result = (char *)ft_calloc(1, 1);
    bytes_read = 1;
    buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
    while (bytes_read > 0)
    {
        //adding buffer to the result until we reach a \n character
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (!check_if_n(buffer))
        {
            result = strjoin(result, buffer);
        }
        else
            break;
    }
    free(buffer);
    result[bytes_read] = '\0';
    return (result);
}

//

char	*get_next_line(int fd)
{
    static char    *result;
    char    *line;

    if (BUFFER_SIZE < 1 || fd < 1)
        return (NULL);
    //in case buffer is large and covers multiple lines, we need to save the information so that on the next function call we can point the next line, and not "lose" them
    //maybe use strchr to start result from the right place
    line = read_file_to_buffer(fd, result);

    return (line);
}

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

char	*get_next_line(int fd)
{
    char    *result;
    ssize_t bytes_read;

    result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    bytes_read = read(fd, result, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (NULL);
    else
        result[BUFFER_SIZE] = '\0';
        return (result);
}

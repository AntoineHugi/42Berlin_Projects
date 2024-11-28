/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:27:32 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/28 12:27:35 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int				counter;
	unsigned int	uc;

	uc = (unsigned int)c;
	counter = write(1, &uc, 1);
	if (counter < 0)
		return (-1);
	else
		return (counter);
}

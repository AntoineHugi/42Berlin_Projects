/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:15:51 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/06 12:43:55 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <ctype.h>*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*int	main(void)
{
	int	test1 = '9';
	char	test2 = '0';
	int	test3 = 123959;
	char test4 = '3';

	test2 = -test2;

	printf("result of test1: %i\n", ft_isdigit(test1));
	printf("result of test2: %i\n", ft_isdigit(test2));
	printf("official result of test2: %i\n", isdigit(test2));	
	printf("result of test3: %i\n", ft_isdigit(test3));
	printf("official result of test3: %i\n", isdigit(test3));	
	printf("result of test4: %i\n", ft_isdigit(test4));
	printf("official result of test4: %i\n", isdigit(test4));
}*/
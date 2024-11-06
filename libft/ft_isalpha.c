/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:17:11 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/06 12:42:30 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int	test1 = 'A';
	int	test2 = 'a';
	int	test3 = 'Z';
	int	test4 = 'z';
	int	test5 = '7';
	int	test6 = 321;
	int	test7 = -6;

	printf("result of test1: %i\n", ft_isalpha(test1));
	printf("result of test2: %i\n", ft_isalpha(test2));
	printf("result of test3: %i\n", ft_isalpha(test3));
	printf("result of test4: %i\n", ft_isalpha(test4));
	printf("result of test5: %i\n", ft_isalpha(test5));
	printf("result of test6: %i\n", ft_isalpha(test6));
	printf("result of test7: %i\n", ft_isalpha(test7));
}
*/
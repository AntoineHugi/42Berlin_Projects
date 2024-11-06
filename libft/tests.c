/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:21:28 by ahugi             #+#    #+#             */
/*   Updated: 2024/11/06 15:21:31 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

int	main(void)
{
	size_t i = 0;
    int	test1 = 'A';
	int	test2 = 'a';
	int	test3 = 'Z';
	int	test4 = 'z';
	int	test5 = '0';
	int	test6 = '9';
	int	test7 = -346;
    char test8 = '\t';
    char testbzero1[] = "tough beans";
    char testbzero2[] = "tough beans";

    printf("\nTesting for isalpha\n");
	printf("result of test1 %i\n", ft_isalpha(test1));
    printf("official result of test1 %i\n", isalpha(test1));
	printf("result of test2 %i\n", ft_isalpha(test2));
    printf("official result of test2 %i\n", isalpha(test2));
	printf("result of test3 %i\n", ft_isalpha(test3));
    printf("official result of test3 %i\n", isalpha(test3));
	printf("result of test4 %i\n", ft_isalpha(test4));
    printf("official result of test4 %i\n", isalpha(test4));
	printf("result of test5 %i\n", ft_isalpha(test5));
    printf("official result of test5 %i\n", isalpha(test5));
	printf("result of test6 %i\n", ft_isalpha(test6));
    printf("official result of test6 %i\n", isalpha(test6));
	printf("result of test7 %i\n", ft_isalpha(test7));
    printf("official result of test7 %i\n", isalpha(test7));
    printf("result of test8 %i\n", ft_isalpha(test8));
    printf("official result of test8 %i\n", isalpha(test8));

    printf("\n\n");
    printf("Testing for isdigit\n");
    printf("result of test1 %i\n", ft_isdigit(test1));
    printf("official result of test1 %i\n", isdigit(test1));
	printf("result of test2 %i\n", ft_isdigit(test2));
    printf("official result of test2 %i\n", isdigit(test2));
	printf("result of test3 %i\n", ft_isdigit(test3));
    printf("official result of test3 %i\n", isdigit(test3));
	printf("result of test4 %i\n", ft_isdigit(test4));
    printf("official result of test4 %i\n", isdigit(test4));
	printf("result of test5 %i\n", ft_isdigit(test5));
    printf("official result of test5 %i\n", isdigit(test5));
	printf("result of test6 %i\n", ft_isdigit(test6));
    printf("official result of test6 %i\n", isdigit(test6));
	printf("result of test7 %i\n", ft_isdigit(test7));
    printf("official result of test7 %i\n", isdigit(test7));
    printf("result of test8 %i\n", ft_isdigit(test8));
    printf("official result of test8 %i\n", isdigit(test8));

    printf("\n\n");
    printf("Testing for isalnum\n");
    printf("result of test1 %i\n", ft_isalnum(test1));
    printf("official result of test1 %i\n", isalnum(test1));
	printf("result of test2 %i\n", ft_isalnum(test2));
    printf("official result of test2 %i\n", isalnum(test2));
	printf("result of test3 %i\n", ft_isalnum(test3));
    printf("official result of test3 %i\n", isalnum(test3));
	printf("result of test4 %i\n", ft_isalnum(test4));
    printf("official result of test4 %i\n", isalnum(test4));
	printf("result of test5 %i\n", ft_isalnum(test5));
    printf("official result of test5 %i\n", isalnum(test5));
	printf("result of test6 %i\n", ft_isalnum(test6));
    printf("official result of test6 %i\n", isalnum(test6));
	printf("result of test7 %i\n", ft_isalnum(test7));
    printf("official result of test7 %i\n", isalnum(test7));
    printf("result of test8 %i\n", ft_isalnum(test8));
    printf("official result of test8 %i\n", isalnum(test8));

    printf("\n\n");
    printf("Testing for isascii\n");
    printf("result of test1 %i\n", ft_isascii(test1));
    printf("official result of test1 %i\n", isascii(test1));
	printf("result of test2 %i\n", ft_isascii(test2));
    printf("official result of test2 %i\n", isascii(test2));
	printf("result of test3 %i\n", ft_isascii(test3));
    printf("official result of test3 %i\n", isascii(test3));
	printf("result of test4 %i\n", ft_isascii(test4));
    printf("official result of test4 %i\n", isascii(test4));
	printf("result of test5 %i\n", ft_isascii(test5));
    printf("official result of test5 %i\n", isascii(test5));
	printf("result of test6 %i\n", ft_isascii(test6));
    printf("official result of test6 %i\n", isascii(test6));
	printf("result of test7 %i\n", ft_isascii(test7));
    printf("official result of test7 %i\n", isascii(test7));
    printf("result of test8 %i\n", ft_isascii(test8));
    printf("official result of test8 %i\n", isascii(test8));

    printf("\n\n");
    printf("Testing for isprint\n");
    printf("result of test1 %i\n", ft_isprint(test1));
    printf("official result of test1 %i\n", isprint(test1));
	printf("result of test2 %i\n", ft_isprint(test2));
    printf("official result of test2 %i\n", isprint(test2));
	printf("result of test3 %i\n", ft_isprint(test3));
    printf("official result of test3 %i\n", isprint(test3));
	printf("result of test4 %i\n", ft_isprint(test4));
    printf("official result of test4 %i\n", isprint(test4));
	printf("result of test5 %i\n", ft_isprint(test5));
    printf("official result of test5 %i\n", isprint(test5));
	printf("result of test6 %i\n", ft_isprint(test6));
    printf("official result of test6 %i\n", isprint(test6));
	printf("result of test7 %i\n", ft_isprint(test7));
    printf("official result of test7 %i\n", isprint(test7));
    printf("result of test8 %i\n", ft_isprint(test8));
    printf("official result of test8 %i\n", isprint(test8));

    printf("\n\n");
    printf("Testing for bzero\n");
    printf("it starts as : ");
    while (i < sizeof(testbzero1))
    {
        printf("%c/", testbzero1[i]);
        i++;
    }
    i = 0;
    ft_bzero(testbzero1, 15);
    bzero(testbzero2, 15);
    printf("\nMy function outputs\n");
    while (i < 12)
    {
        printf("%c/", testbzero1[i]);
        i++;
    }
    i = 0;
    printf("\nreal function outputs\n");  
    while (i < 12)
    {
        printf("%c/", testbzero2[i]);
        i++;
    }
    printf("\n");
}

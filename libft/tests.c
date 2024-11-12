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

#include <bsd/string.h>
#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

char	f1(unsigned int a, char b)
{
	char	result;

	result = a + b;
	return (result);
}

void	f2(unsigned int a, char *b)
{
	*b = a + *b;
}

int	main(void)
{
	size_t	i = 0;
	int	test1 = 'A';
	int	test2 = 'a';
	int	test3 = 'Z';
	int	test4 = 'z';
	int	test5 = '0';
	int	test6 = '9';
	int	test7 = -346;
	char test8 = '\t';
	char	testbzero1[] = "tough beans";
	char	testbzero2[] = "tough beans";
	char	teststrlen[] = "hello world";
	char	teststrchr[] = "hello";
	char	teststrchrc = 'l';
	char	testcmp1[] = "hello world";
	char	testcmp2[] = "hello world!";
	int		difflength = 12;
	char	teststrnstrb[] = "hello world";
	char	teststrnstrl[] = "";
	int		teststrnstrn = 15;
	char	testatoi1[] = "    	+0217";
	char	teststrlcatsrc2[50] = "hello world";
	char	teststrlcatdest2[50] = "well ";
	char	teststrlcatsrc1[50] = "hello world";
	char	teststrlcatdest1[50] = "well ";
	char	testmemchr[] = "hello world";
	int		testmemchrc = 119;
	char	testmemcmp1[] = "world";
	char	testmemcmp2[] = "hello";
	int	testmemcmp3[] = {1, 2, 7};
	int	testmemcmp4[] = {1, 2, 4};
	char	testmemcpy1[6] = "hello";
	char	testmemcpy2[6] = "world";
	char	testmemcpy3[6] = "hello";
	char	testmemcpy4[6] = "world";
	size_t	testmemcpyn = 5;
	char	testmemmove1[12] = "hello world";
	char	testmemmove2[12] = "hello world";
	size_t	testmemmoven = 2;
	char	testmemset1[] = "hello";
	char	testmemset2[] = "hello";
	int	testmemsetc = 65;
	size_t	testmemsetn = 4;
	size_t	testcallocnmemb = 4;
	size_t	testcallocsize = 1;
	char	*callocptr1;
	char	*callocptr2;
	int		*callocptr3;
	int		*callocptr4;
	char	teststrdupsrc[] = "hello world";
	char	testsubstr[] = "hello world";
	char	teststrjoin1[] = "hello ";
	char	teststrjoin2[] = "world";
	char	testsplit[] = "hello,world,how,,are,you?";
	char	testsplitsep = ',';
	char	**splitresult;
	int		testitoa = -1213;
	char	teststrmapi[] = "1234";
	char	teststriteri[] = "1234";
	char	testtrimstr[] = "//hello//";
	char	testtrimset[] = "//";

	printf("\nTesting for isalpha\n");
	printf("result of test1          %i\n", ft_isalpha(test1));
	printf("official result of test1 %i\n", isalpha(test1));
	printf("result of test2          %i\n", ft_isalpha(test2));
	printf("official result of test2 %i\n", isalpha(test2));
	printf("result of test3          %i\n", ft_isalpha(test3));
	printf("official result of test3 %i\n", isalpha(test3));
	printf("result of test4          %i\n", ft_isalpha(test4));
	printf("official result of test4 %i\n", isalpha(test4));
	printf("result of test5          %i\n", ft_isalpha(test5));
	printf("official result of test5 %i\n", isalpha(test5));
	printf("result of test6          %i\n", ft_isalpha(test6));
	printf("official result of test6 %i\n", isalpha(test6));
	printf("result of test7          %i\n", ft_isalpha(test7));
	printf("official result of test7 %i\n", isalpha(test7));
	printf("result of test8          %i\n", ft_isalpha(test8));
	printf("official result of test8 %i\n", isalpha(test8));

	printf("\n\n");
	printf("Testing for isdigit\n");
	printf("result of test1          %i\n", ft_isdigit(test1));
	printf("official result of test1 %i\n", isdigit(test1));
	printf("result of test2          %i\n", ft_isdigit(test2));
	printf("official result of test2 %i\n", isdigit(test2));
	printf("result of test3          %i\n", ft_isdigit(test3));
	printf("official result of test3 %i\n", isdigit(test3));
	printf("result of test4          %i\n", ft_isdigit(test4));
	printf("official result of test4 %i\n", isdigit(test4));
	printf("result of test5          %i\n", ft_isdigit(test5));
	printf("official result of test5 %i\n", isdigit(test5));
	printf("result of test6          %i\n", ft_isdigit(test6));
	printf("official result of test6 %i\n", isdigit(test6));
	printf("result of test7          %i\n", ft_isdigit(test7));
	printf("official result of test7 %i\n", isdigit(test7));
	printf("result of test8          %i\n", ft_isdigit(test8));
	printf("official result of test8 %i\n", isdigit(test8));

	printf("\n\n");
	printf("Testing for isalnum\n");
	printf("result of test1          %i\n", ft_isalnum(test1));
	printf("official result of test1 %i\n", isalnum(test1));
	printf("result of test2          %i\n", ft_isalnum(test2));
	printf("official result of test2 %i\n", isalnum(test2));
	printf("result of test3          %i\n", ft_isalnum(test3));
	printf("official result of test3 %i\n", isalnum(test3));
	printf("result of test4          %i\n", ft_isalnum(test4));
	printf("official result of test4 %i\n", isalnum(test4));
	printf("result of test5          %i\n", ft_isalnum(test5));
	printf("official result of test5 %i\n", isalnum(test5));
	printf("result of test6          %i\n", ft_isalnum(test6));
	printf("official result of test6 %i\n", isalnum(test6));
	printf("result of test7          %i\n", ft_isalnum(test7));
	printf("official result of test7 %i\n", isalnum(test7));
	printf("result of test8          %i\n", ft_isalnum(test8));
	printf("official result of test8 %i\n", isalnum(test8));

	printf("\n\n");
	printf("Testing for isascii\n");
	printf("result of test1          %i\n", ft_isascii(test1));
	printf("official result of test1 %i\n", isascii(test1));
	printf("result of test2          %i\n", ft_isascii(test2));
	printf("official result of test2 %i\n", isascii(test2));
	printf("result of test3          %i\n", ft_isascii(test3));
	printf("official result of test3 %i\n", isascii(test3));
	printf("result of test4          %i\n", ft_isascii(test4));
	printf("official result of test4 %i\n", isascii(test4));
	printf("result of test5          %i\n", ft_isascii(test5));
	printf("official result of test5 %i\n", isascii(test5));
	printf("result of test6          %i\n", ft_isascii(test6));
	printf("official result of test6 %i\n", isascii(test6));
	printf("result of test7          %i\n", ft_isascii(test7));
	printf("official result of test7 %i\n", isascii(test7));
	printf("result of test8          %i\n", ft_isascii(test8));
	printf("official result of test8 %i\n", isascii(test8));

	printf("\n\n");
	printf("Testing for isprint\n");
	printf("result of test1          %i\n", ft_isprint(test1));
	printf("official result of test1 %i\n", isprint(test1));
	printf("result of test2          %i\n", ft_isprint(test2));
	printf("official result of test2 %i\n", isprint(test2));
	printf("result of test3          %i\n", ft_isprint(test3));
	printf("official result of test3 %i\n", isprint(test3));
	printf("result of test4          %i\n", ft_isprint(test4));
	printf("official result of test4 %i\n", isprint(test4));
	printf("result of test5          %i\n", ft_isprint(test5));
	printf("official result of test5 %i\n", isprint(test5));
	printf("result of test6          %i\n", ft_isprint(test6));
	printf("official result of test6 %i\n", isprint(test6));
	printf("result of test7          %i\n", ft_isprint(test7));
	printf("official result of test7 %i\n", isprint(test7));
	printf("result of test8          %i\n", ft_isprint(test8));
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
	ft_bzero(testbzero1, 5);
	bzero(testbzero2, 5);
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

	printf("\n\n");
	printf("Testing for strlen\n");
	printf("The length of %s is\n", teststrlen);
	printf("mine    : %zu\n", ft_strlen(teststrlen));
	printf("official: %zu\n", strlen(teststrlen));

	printf("\n\n");
	printf("Testing for strchr\n");
	printf("pointer to first occurence of %c in %s is\n", teststrchrc, teststrchr);
	printf("mine    : %s\n", ft_strchr(teststrchr, teststrchrc));
	printf("official: %s\n", strchr(teststrchr, teststrchrc));

	printf("\n\n");
	printf("Testing for strrchr\n");
	printf("pointer to last occurence of %c in %s is\n", teststrchrc, teststrchr);
	printf("mine    : %s\n", ft_strrchr(teststrchr, teststrchrc));
	printf("official: %s\n", strrchr(teststrchr, teststrchrc));

	printf("\n\n");
	printf("Testing for strncmp\n");
	printf("difference between %s and %s until character %d is\n", testcmp1, testcmp2, difflength);
	printf("mine    : %d\n", ft_strncmp(testcmp1, testcmp2, difflength));
	printf("official: %d\n", strncmp(testcmp1, testcmp2, difflength));

	printf("\n\n");
	printf("Testing for strnstr\n");
	printf("The first occurence of %s in %s until character %d is\n", teststrnstrl, teststrnstrb, teststrnstrn);
	printf("mine    : %s\n", ft_strnstr(teststrnstrb, teststrnstrl, teststrnstrn));
	printf("official: %s\n", strnstr(teststrnstrb, teststrnstrl, teststrnstrn));

	printf("\n\n");
	printf("Testing for atoi\n");
	printf("The string %s turned into int become:\n", testatoi1);
	printf("mine    : %d\n", ft_atoi(testatoi1));
	printf("official: %d\n", atoi(testatoi1));

	printf("\n\n");
	printf("Testing for strlcat\n");
	printf("The strlcat of %s with %s results in\n", teststrlcatdest1, teststrlcatsrc1);
	printf("mine    : %zu\n", ft_strlcat(teststrlcatdest1, teststrlcatsrc1, 10));
	printf("official: %zu\n", strlcat(teststrlcatdest2, teststrlcatsrc2, 10));
	printf("my dest     : %s\n", teststrlcatdest1);
	printf("official    : %s\n", teststrlcatdest2);

	printf("\n\n");
	printf("Testing for memchr\n");
	printf("looking for %c in %s\n", testmemchrc, testmemchr);
	printf("my result       : %s\n", (char*)ft_memchr(testmemchr, testmemchrc, 20));
	printf("official result : %s\n", (char*)memchr(testmemchr, testmemchrc, 20));

	printf("\n\n");
	printf("Testing for memcmp\n");
	printf("comparing for %s and %s\n", testmemcmp1, testmemcmp2);
	printf("my result       : %i\n", ft_memcmp(testmemcmp1, testmemcmp2, 5));
	printf("official result : %i\n", memcmp(testmemcmp1, testmemcmp2, 5));
	printf("comparing for %s and %s\n", testmemcmp1, testmemcmp1);
	printf("my result       : %i\n", ft_memcmp(testmemcmp1, testmemcmp1, 5));
	printf("official result : %i\n", memcmp(testmemcmp1, testmemcmp1, 5));
	printf("comparing for %s and %s\n", testmemcmp2, testmemcmp1);
	printf("my result       : %i\n", ft_memcmp(testmemcmp2, testmemcmp1, 5));
	printf("official result : %i\n", memcmp(testmemcmp2, testmemcmp1, 5));
	printf("comparing int array\n");
	printf("my result       : %i\n", ft_memcmp(testmemcmp3, testmemcmp4, sizeof(int)*3));
	printf("official result : %i\n", memcmp(testmemcmp3, testmemcmp4, sizeof(int)*3));

	printf("\n\n");
	printf("Testing for memcpy\n");
	printf("copying %s on %s up to byte %zu\n", testmemcpy2, testmemcpy1, testmemcpyn);
	printf("my result       : %s\n", (char*)ft_memcpy(testmemcpy1, testmemcpy2, testmemcpyn));
	printf("official result : %s\n", (char*)memcpy(testmemcpy3, testmemcpy4, testmemcpyn));

	printf("\n\n");
	printf("Testing for memmove\n");
	printf("copying %zu bytes from %s on %s \n", testmemmoven, testmemmove1, (testmemmove1 + 5));
	printf("my result       : %s\n", (char*)ft_memmove((testmemmove1 + 5), testmemmove1, testmemmoven));
	printf("official result : %s\n", (char*)memmove((testmemmove2 + 5), testmemmove2, testmemmoven));

	printf("\n\n");
	printf("Testing for memset\n");
	printf("copying %i on %s up to byte %zu\n", testmemsetc, testmemset1, testmemsetn);
	printf("my result       : %s\n", (char*)ft_memset(testmemset1, testmemsetc, testmemsetn));
	printf("official result : %s\n", (char*)memset(testmemset2, testmemsetc, testmemsetn));

	printf("\n\n");
	printf("Testing calloc for char array\n");
	i = 0;
	printf("my function outputs\n");  
	callocptr1 = (char*)ft_calloc(testcallocnmemb, testcallocsize);
	while (i < testcallocnmemb*testcallocsize)
	{
		printf("%c/", callocptr1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("\nreal function outputs\n"); 
	callocptr2 = (char*)calloc(testcallocnmemb, testcallocsize);
	while (i < testcallocnmemb*testcallocsize)
	{
		printf("%c/", callocptr2[i]);
		i++;
	}
	printf("\n");
	printf("Testing calloc for int array\n");
	i = 0;
	printf("my function outputs\n");  
	callocptr3 = (int*)ft_calloc(testcallocnmemb, testcallocsize);
	while (i < testcallocnmemb*testcallocsize)
	{
		printf("%i/", callocptr3[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("\nreal function outputs\n"); 
	callocptr4 = (int*)calloc(testcallocnmemb, testcallocsize);
	while (i < testcallocnmemb*testcallocsize)
	{
		printf("%i/", callocptr4[i]);
		i++;
	}
	printf("\n");

	printf("\n\n");
	printf("Testing strdup\n");
	printf("my function outputs:\n %s \n", ft_strdup(teststrdupsrc));
	printf("official function outputs:\n %s \n", strdup(teststrdupsrc));

	printf("\n\n");
	printf("Testing substr\n");
	printf("my function outputs:\n %s \n", ft_substr(testsubstr, 6, 5));

	printf("\n\n");
	printf("Testing strjoin\n");
	printf("my function outputs:\n %s \n", ft_strjoin(teststrjoin1, teststrjoin2));

	printf("\n\n");
	printf("Testing split\n");
	splitresult = ft_split(testsplit, testsplitsep);
	i = 0;
	while (splitresult[i])
	{
		printf("my function outputs:%s \n", splitresult[i]);
		i++;
	}

	printf("\n\n");
	printf("Testing itoa\n");
	printf("My function turns %i into %s\n", testitoa, ft_itoa(testitoa));

	printf("\n\n");
	printf("Testing strmapi\n");
	printf("My function transform %s to %s\n", teststrmapi, ft_strmapi(teststrmapi, f1));

	printf("\n\n");
	printf("Testing striteri\n");
	printf("My function transform %s ", teststriteri);
	ft_striteri(teststriteri, f2);
	printf("to %s\n", teststriteri);

	printf("\n\n");
	printf("Testing ft_putchar_fd\n");
	ft_putchar_fd('A', 1);

	printf("\n\n");
	printf("Testing ft_putstr_fd\n");
	ft_putstr_fd("hello", 1);

	printf("\n\n");
	printf("Testing ft_putendl_fd\n");
	ft_putendl_fd("hello", 1);

	printf("\n\n");
	printf("Testing ft_putnbr_fd\n");
	ft_putnbr_fd(1122345, 1);

	printf("\n\n");
	printf("Testing strtrim\n");
	printf("testing trimming %s of characters %s, which become %s", testtrimstr, testtrimset, ft_strtrim(testtrimstr, testtrimset));
}
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	test_int = -6809;
	int	test_d = 700;
	int	test_char = -1185;
	char	*test_string = NULL;
	unsigned int	test_x = 34522;
	void	*ptr = &test_string;
	int	my_result;
	int	off_result;

    my_result = 0;
	off_result = 0;

	ft_printf("\n  my tests \n");
	my_result += ft_printf("i test is %i \nd test is %d \nc test is %c \ns test is %s \n", test_int, test_d, test_char, test_string);
	my_result += ft_printf("u test is %u \nx test is %x \nX test is %X \np test is %p \npercent test is %%\n", test_int, test_x, test_x, ptr);

	ft_printf("\n  official tests \n");
	off_result += printf("i test is %i \nd test is %d \nc test is %c \ns test is %s \n", test_int, test_d, test_char, test_string);
	off_result += printf("u test is %u \nx test is %x \nX test is %X \np test is %p \npercent test is %%\n", test_int, test_x, test_x, ptr);

	ft_printf("\nmy result is %i, official result is %i\n", my_result, off_result);
	return (my_result);
}
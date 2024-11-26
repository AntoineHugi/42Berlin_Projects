CUR_DIR = $(shell pwd)

NAME = libftprintf.a

CC = cc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/ft_itoa_hex.c $(CUR_DIR)/ft_itoa_hex_pointer.c $(CUR_DIR)/ft_printchar.c \
	    $(CUR_DIR)/ft_printf.c $(CUR_DIR)/ft_printhex.c $(CUR_DIR)/ft_printnum.c \
	    $(CUR_DIR)/ft_printpointer.c $(CUR_DIR)/ft_printstr.c $(CUR_DIR)/ft_toupper_str.c

MY_HEADERS = printf.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME) 

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS)

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

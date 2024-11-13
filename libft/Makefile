CUR_DIR = $(shell pwd)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS += -Wall -Wextra -Werror

MY_SOURCES = $(CUR_DIR)/ft_atoi.c $(CUR_DIR)/ft_bzero.c $(CUR_DIR)/ft_calloc.c \
	     $(CUR_DIR)/ft_isalnum.c $(CUR_DIR)/ft_isalpha.c $(CUR_DIR)/ft_isascii.c \
	     $(CUR_DIR)/ft_isdigit.c $(CUR_DIR)/ft_isprint.c $(CUR_DIR)/ft_itoa.c \
	     $(CUR_DIR)/ft_memchr.c $(CUR_DIR)/ft_memcmp.c $(CUR_DIR)/ft_memcpy.c \
	     $(CUR_DIR)/ft_memmove.c $(CUR_DIR)/ft_memset.c $(CUR_DIR)/ft_putchar_fd.c \
	     $(CUR_DIR)/ft_putendl_fd.c $(CUR_DIR)/ft_putnbr_fd.c $(CUR_DIR)/ft_putstr_fd.c \
	     $(CUR_DIR)/ft_split.c $(CUR_DIR)/ft_strchr.c $(CUR_DIR)/ft_strdup.c \
	     $(CUR_DIR)/ft_striteri.c $(CUR_DIR)/ft_strjoin.c $(CUR_DIR)/ft_strlcat.c \
	     $(CUR_DIR)/ft_strlcpy.c $(CUR_DIR)/ft_strlen.c $(CUR_DIR)/ft_strmapi.c \
	     $(CUR_DIR)/ft_strncmp.c $(CUR_DIR)/ft_strnstr.c $(CUR_DIR)/ft_strrchr.c \
	     $(CUR_DIR)/ft_strtrim.c $(CUR_DIR)/ft_substr.c $(CUR_DIR)/ft_tolower.c \
	     $(CUR_DIR)/ft_toupper.c

MY_HEADERS = includes/libft.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all:	$(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS) 

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c -o

clean: 	
	$(RM) $(MY_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all 

.PHONY: all clean fclean re


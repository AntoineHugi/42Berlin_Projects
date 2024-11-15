CUR_DIR = $(shell pwd)

NAME = libft.a

CC = cc

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

MY_SOURCES_BONUS = $(CUR_DIR)/ft_lstnew.c $(CUR_DIR)/ft_lstadd_front.c $(CUR_DIR)/ft_lstsize.c \
				   $(CUR_DIR)/ft_lstlast.c $(CUR_DIR)/ft_lstadd_back.c $(CUR_DIR)/ft_lstdelone.c \
				   $(CUR_DIR)/ft_lstclear.c $(CUR_DIR)/ft_lstiter.c $(CUR_DIR)/ft_lstmap.c

MY_HEADERS = libft.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

all:	$(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $(NAME) $(MY_OBJECTS) 

%.o: %.c $(MY_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 	
	$(RM) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

bonus:	$(MY_OBJECTS) $(MY_OBJECTS_BONUS)
	ar rcs $(NAME) $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

.PHONY: all clean fclean re bonus

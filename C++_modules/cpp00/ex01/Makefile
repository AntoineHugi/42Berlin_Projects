CUR_DIR = $(shell pwd)

NAME = phonebook_3000

CC = c++

RM = rm -f

CPPFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS = $(CUR_DIR)/  .cpp

OBJS = $(SRCS:.cpp=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean: 	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

CUR_DIR = $(shell pwd)

NAME = phonebook3000

CC = c++

RM = rm -f

CPPFLAGS += -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS = $(CUR_DIR)/main.cpp Contacts.cpp PhoneBook.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean: 	
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

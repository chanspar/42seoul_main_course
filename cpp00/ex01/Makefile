CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Contact.cpp PhoneBook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
INCS = Contact.hpp PhoneBook.hpp
NAME = phonebook

all: $(NAME)

%.o: %.cpp $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

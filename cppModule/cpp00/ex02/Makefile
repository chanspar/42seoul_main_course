CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
INCS = Account.hpp
NAME = account

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

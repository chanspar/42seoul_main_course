CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
INCS = Zombie.hpp
NAME = zombie

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

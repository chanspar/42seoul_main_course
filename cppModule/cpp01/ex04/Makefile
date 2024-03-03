CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)
NAME = replace

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

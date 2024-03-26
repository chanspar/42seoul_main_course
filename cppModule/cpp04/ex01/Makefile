CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp
OBJS = $(SRCS:.cpp=.o)
INCS = Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp
NAME = a.out

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

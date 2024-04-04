CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp AMateria.cpp MateriaSource.cpp Character.cpp Ice.cpp Cure.cpp
OBJS = $(SRCS:.cpp=.o)
INCS = Cure.hpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp \
	MateriaSource.hpp Character.hpp Ice.hpp
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

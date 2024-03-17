NAME = libgnl.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
INCS = -Iget_next_line.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) -I$(INCS) $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean :
	$(MAKE) clean
	rm -f $(NAME)
	
re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus

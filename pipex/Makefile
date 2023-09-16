# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 21:45:16 by chanspar          #+#    #+#              #
#    Updated: 2023/09/16 04:28:10 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = libft_utils.c pipex.c split.c err.c parsing.c whitespace.c check.c process.c
OBJS = $(SRCS:%.c=%.o)
HEADER = ./

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

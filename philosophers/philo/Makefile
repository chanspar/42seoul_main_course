# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:19:02 by chanspar          #+#    #+#              #
#    Updated: 2023/12/19 15:09:39 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = philo.c parse.c utils.c error.c
OBJS = $(SRCS:%.c=%.o)
HEADER = philo.h

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

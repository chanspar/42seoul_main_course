# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 17:28:38 by chanspar          #+#    #+#              #
#    Updated: 2023/09/04 16:33:45 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = error.c linked_list.c push_pop.c swap.c greedy.c min_execute.c push_swap.c reverse_rotate.c\
	div.c push.c rotate.c combi_utils.c	pivot.c 
SRCS_BONUS = checker_bonus.c err_bonus.c
SRCS_BONUS_NEED = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c linked_list.c\
	push.c rotate.c reverse_rotate.c swap.c push_pop.c
OBJS = $(SRCS:%.c=%.o)
HEADER = ./
LIB_DIR = ./libft
LIB = ft

ifdef IS_BONUS
	SRC = $(SRCS_BONUS) $(SRCS_BONUS_NEED)
	OBJ = $(SRC:%.c=%.o)
	NAME = checker
else
	OBJ = $(OBJS)
	SRC = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean :
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf *.o get_next_line/*.o

fclean : clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf push_swap checker

re :
	$(MAKE) fclean
	$(MAKE) all

bonus :
	IS_BONUS=1 make all

.PHONY: all clean fclean re bonus

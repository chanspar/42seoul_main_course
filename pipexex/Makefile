# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 21:45:16 by chanspar          #+#    #+#              #
#    Updated: 2023/09/25 20:51:12 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = libft_utils.c pipex.c split.c err.c parsing.c whitespace.c check.c process.c
SRCS_BONUS = check_bonus.c gnl_bonus.c libft_util1_bonus.c multiple_bonus.c err_bonus.c\
            here_doc_bonus.c libft_util2_bonus.c parsing_bonus.c split_bonus.c free_bonus.c\
			heredoc_process_bonus.c mp_f_l_bonus.c pipex_bonus.c whitespace_bonus.c err_hd_bonus.c
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = ${addprefix bonus/, $(SRCS_BONUS:%.c=%.o)}
HEADER = ./
HEADER_BONUS = bonus/pipex_bonus.h

ifdef IS_BONUS
	OBJ = $(OBJS_BONUS)
	H = $(HEADER_BONUS)
else
	OBJ = $(OBJS)
	H = $(HEADER)
endif

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(H)

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

bonus :
	IS_BONUS=1 make all

.PHONY: all clean fclean re bonus

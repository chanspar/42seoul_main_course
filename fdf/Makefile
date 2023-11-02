# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 18:14:06 by chanspar          #+#    #+#              #
#    Updated: 2023/11/02 18:19:47 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
SRCS = fdf.c err.c libft_utils.c libft_utils1.c gnl.c init.c split.c whitespace.c\
		coordinate.c isometric.c line.c color.c event.c mlx_utils.c
OBJS = $(SRCS:%.c=%.o)
HEADER = ./
MLX_DIR = ./minilibx_mms_20210621
MLX = mlx
MLX_EXE = libmlx.dylib

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) -o $(NAME) $(OBJS)
	@cd $(MLX_DIR) && mv $(MLX_EXE) ../

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean :
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJS)
	@rm -rf $(MLX_EXE)

fclean : clean
	@rm -rf $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

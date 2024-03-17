# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 13:27:04 by doukim            #+#    #+#              #
#    Updated: 2024/03/16 19:13:29 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
CC		:= cc -g
INCLUDE	:= -I./incs -I./libs/libft -I./libs/get_next_line -I./libs/mlx
CFLAGS	:= -Wall -Wextra -Werror
FUNCS	:= \
	-L./libs/mlx -lmlx\
	-L./libs/libft -lft\
	-L./libs/get_next_line -lgnl

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/

SRCS	:= c3d_error.c c3d_get_map_resource_utils.c c3d_key_move.c c3d_tex.c \
		c3d_floor_ceiling.c c3d_get_map_shape_utils.c c3d_key_rotate.c \
		c3d_wall.c c3d_free.c c3d_get_map_utils.c c3d_main.c c3d_get_filename.c \
		c3d_init.c c3d_mlx.c c3d_get_map.c c3d_key_event.c c3d_raycast.c
			
OBJS	:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
LIBS	:= \
	./libs/libft/libft.a\
	./libs/get_next_line/libgnl.a\
	./libs/mlx/libmlx.a

bonus : all

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libs/libft bonus
	$(MAKE) -C ./libs/get_next_line all
	$(MAKE) -C ./libs/mlx all
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(FUNCS) -framework OpenGL \
		-framework Appkit

$(OBJDIR) :
	@mkdir objs

$(OBJDIR)%.o : $(SRCDIR)%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJDIR)
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/get_next_line clean
	$(MAKE) -C ./libs/mlx clean

fclean : clean
	$(MAKE) -C ./libs/libft fclean
	$(MAKE) -C ./libs/get_next_line fclean
	rm -rf ./libs/mlx/libmlx.a
	rm -rf $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

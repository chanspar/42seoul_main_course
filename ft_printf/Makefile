# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 20:19:25 by chanspar          #+#    #+#              #
#    Updated: 2023/07/03 16:03:17 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_print_decimal.c\
	ft_print_hexadecimal.c\
	ft_print_pointer.c\
	ft_print_str.c\
	ft_print_unsigned_decimal.c\
	ft_printf.c	
OBJS = $(SRCS:.c=.o)
HEADER = ./

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
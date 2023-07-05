/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:42:21 by chanspar          #+#    #+#             */
/*   Updated: 2023/07/03 15:46:42 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		check_type(char c, va_list ap);
int		c_type(va_list ap);
int		s_type(va_list ap);
int		print_decimal(int n);
int		find_len(int n);
int		d_type(va_list ap);
int		find_unsigned_len(unsigned int n);
int		print_unsigned_decimal(unsigned int n);
int		u_type(va_list ap);
int		find_hexa_len(unsigned long n);
int		print_pointer(unsigned long n);
int		p_type(va_list ap);
int		print_hexa_lower(unsigned int n);
int		print_hexa_upper(unsigned int n);
int		x_type(va_list ap);
int		x_upper_type(va_list ap);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:14:11 by chanspar          #+#    #+#             */
/*   Updated: 2023/07/03 15:46:33 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char c, va_list ap)
{
	if (c == 'c')
		return (c_type(ap));
	if (c == 's')
		return (s_type(ap));
	if (c == 'p')
		return (p_type(ap));
	if (c == 'd' || c == 'i')
		return (d_type(ap));
	if (c == 'u')
		return (u_type(ap));
	if (c == 'x')
		return (x_type(ap));
	if (c == 'X')
		return (x_upper_type(ap));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		return_result;

	len = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			return_result = check_type(*(++format), ap);
			if (return_result == -1)
				return (-1);
			len += return_result;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}

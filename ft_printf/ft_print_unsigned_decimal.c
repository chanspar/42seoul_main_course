/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:11:50 by chanspar          #+#    #+#             */
/*   Updated: 2023/06/30 20:17:40 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_unsigned_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	print_unsigned_decimal(unsigned int n)
{
	char	a;

	if (n >= 10)
	{
		if (print_unsigned_decimal(n / 10) == -1)
			return (-1);
		if (print_unsigned_decimal(n % 10) == -1)
			return (-1);
	}
	else
	{
		a = n + '0';
		return (write(1, &a, 1));
	}
	return (0);
}

int	u_type(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, unsigned int);
	if (print_unsigned_decimal(u) == -1)
		return (-1);
	return (find_unsigned_len(u));
}

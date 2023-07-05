/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:16:12 by chanspar          #+#    #+#             */
/*   Updated: 2023/06/30 20:17:52 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	print_decimal(int n)
{
	char	a;

	if (n >= 10 || n <= -10)
	{
		if (print_decimal(n / 10) == -1)
			return (-1);
		if (print_decimal(n % 10) == -1)
			return (-1);
	}
	else if (0 <= n && n < 10)
	{
		a = n + '0';
		return (write(1, &a, 1));
	}
	else
	{
		a = n * -1 + '0';
		return (write(1, &a, 1));
	}
	return (0);
}

int	d_type(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	if (d < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
	}
	if (print_decimal(d) == -1)
		return (-1);
	return (find_len(d));
}

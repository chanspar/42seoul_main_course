/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:56:40 by chanspar          #+#    #+#             */
/*   Updated: 2023/06/30 20:17:51 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_lower(unsigned int n)
{
	if (n >= 16)
	{
		if (print_hexa_lower(n / 16) == -1)
			return (-1);
		if (print_hexa_lower(n % 16) == -1)
			return (-1);
	}
	else
		return (write(1, &"0123456789abcdef"[n], 1));
	return (0);
}

int	print_hexa_upper(unsigned int n)
{
	if (n >= 16)
	{
		if (print_hexa_upper(n / 16) == -1)
			return (-1);
		if (print_hexa_upper(n % 16) == -1)
			return (-1);
	}
	else
		return (write(1, &"0123456789ABCDEF"[n], 1));
	return (0);
}

int	x_type(va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	if (print_hexa_lower(x) == -1)
		return (-1);
	return (find_hexa_len(x));
}

int	x_upper_type(va_list ap)
{
	unsigned int	x_upper;

	x_upper = va_arg(ap, unsigned int);
	if (print_hexa_upper(x_upper) == -1)
		return (-1);
	return (find_hexa_len(x_upper));
}

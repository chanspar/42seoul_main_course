/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:35:06 by chanspar          #+#    #+#             */
/*   Updated: 2023/06/30 20:17:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_hexa_len(unsigned long n)
{
	int	len;

	len = 1;
	while (n / 16 != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	print_pointer(unsigned long n)
{
	if (n >= 16)
	{
		if (print_pointer(n / 16) == -1)
			return (-1);
		if (print_pointer(n % 16) == -1)
			return (-1);
	}
	else
		return (write(1, &"0123456789abcdef"[n], 1));
	return (0);
}

int	p_type(va_list ap)
{
	unsigned long	p;

	p = va_arg(ap, unsigned long);
	if (p == 0)
	{
		return (write(1, "0x0", 3));
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (print_pointer(p) == -1)
		return (-1);
	return (find_hexa_len(p) + 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:00:46 by chanspar          #+#    #+#             */
/*   Updated: 2023/07/03 15:46:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_type(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	s_type(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == 0)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

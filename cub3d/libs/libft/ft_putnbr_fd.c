/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:36 by doukim            #+#    #+#             */
/*   Updated: 2023/03/23 16:18:07 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_putnbr_fd(long long nbr, int fd)
{
	if (nbr / 10)
		ft_recursive_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	tmp;

	tmp = (long long)n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp = -tmp;
	}
	ft_recursive_putnbr_fd(tmp, fd);
	return ;
}

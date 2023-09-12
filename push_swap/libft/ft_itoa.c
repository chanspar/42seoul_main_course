/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:50:26 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/30 17:54:03 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
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

static void	put_str(char *p, int n_len, int n)
{
	int	i;

	i = n_len - 1;
	if (n < 0)
	{	
		p[0] = '-';
		while (i > 0)
		{
			p[i] = n % 10 * -1 + '0';
			n /= 10;
			i--;
		}
	}
	else
	{
		while (i >= 0)
		{
			p[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
	p[n_len] = 0;
}

char	*ft_itoa(int n)
{
	char	*p;
	int		n_len;

	n_len = find_len(n);
	p = (char *)malloc(sizeof(char) * (n_len + 1));
	if (p == 0)
		return (0);
	put_str(p, n_len, n);
	return (p);
}

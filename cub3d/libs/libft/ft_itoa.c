/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:40:36 by doukim            #+#    #+#             */
/*   Updated: 2023/03/26 21:46:39 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *s)
{
	const size_t	len = ft_strlen(s);
	size_t			idx;
	char			tmp;

	idx = 0;
	while (idx < len / 2)
	{
		tmp = s[idx];
		s[idx] = s[len - idx - 1];
		s[len - idx - 1] = tmp;
		idx++;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char		revnum[35];
	long long	tmp;
	int			isminus;
	size_t		idx;

	if (!n)
		return (ft_strdup("0"));
	isminus = (n < 0);
	tmp = (1LL - 2 * (n < 0)) * n;
	idx = 0;
	while (tmp)
	{
		revnum[idx++] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (isminus)
		revnum[idx++] = '-';
	revnum[idx] = '\0';
	ft_strrev(revnum);
	return (ft_strdup(revnum));
}

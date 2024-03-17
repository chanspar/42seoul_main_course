/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:55:58 by doukim            #+#    #+#             */
/*   Updated: 2023/03/15 17:15:24 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;
	int		tmp;

	idx = 0;
	while (idx < n)
	{
		tmp = ((const unsigned char *)s1)[idx] - \
		((const unsigned char *)s2)[idx];
		if (tmp)
			return (tmp);
		idx++;
	}
	return (0);
}

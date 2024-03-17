/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:32:50 by doukim            #+#    #+#             */
/*   Updated: 2023/03/16 19:05:19 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (src > dst)
	{
		idx = 0;
		while (idx < len)
		{
			((char *)dst)[idx] = ((const char *)src)[idx];
			idx++;
		}
	}
	else
	{
		idx = 0;
		while (idx < len)
		{
			((char *)dst)[len - idx - 1] = ((const char *)src)[len - idx - 1];
			idx++;
		}
	}
	return (dst);
}

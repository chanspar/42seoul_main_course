/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:45:06 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/23 22:45:03 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = dst;
	tmp2 = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst <= src)
	{
		while (len-- > 0)
		{
			*tmp1 = *tmp2;
			tmp1++;
			tmp2++;
		}
	}
	else
	{
		while (len-- > 0)
		{
			tmp1[len] = tmp2[len];
		}
	}
	return (dst);
}

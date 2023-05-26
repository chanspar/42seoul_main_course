/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:50:19 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/24 21:43:57 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	tmp;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != 0)
	{
		j = 0;
		tmp = i;
		while (haystack[tmp] == needle[j] && tmp < len && haystack[tmp] != 0)
		{
			tmp++;
			j++;
		}
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

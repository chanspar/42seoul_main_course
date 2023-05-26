/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:54:48 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/25 02:58:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		tmp = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	while (i < len && *(s + start) != 0 && s[i] != 0)
	{
		*(tmp + i) = *(s + start);
		i++;
		start++;
	}
	*(tmp + i) = 0;
	return (tmp);
}

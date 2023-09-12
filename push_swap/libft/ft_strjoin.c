/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:01:02 by chanspar          #+#    #+#             */
/*   Updated: 2023/05/05 17:38:13 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*p;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	p = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (p == 0)
		return (0);
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		p[i] = s2[i - s1_len];
		i++;
	}
	p[i] = 0;
	return (p);
}

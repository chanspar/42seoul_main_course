/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:03:10 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/24 22:12:51 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		src_len;	
	char		*p;
	char		*tmp;

	src_len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (src_len + 1));
	if (p == 0)
		return (0);
	tmp = p;
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	*p = 0;
	return (tmp);
}

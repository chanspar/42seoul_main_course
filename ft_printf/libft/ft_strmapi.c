/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:43:34 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/30 14:46:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*p;

	i = 0;
	s_len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (p == 0)
		return (0);
	while (*(s + i) != 0)
	{
		p[i] = f(i, *(s + i));
		i++;
	}
	p[i] = 0;
	return (p);
}

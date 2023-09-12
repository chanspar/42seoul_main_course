/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:07:10 by chanspar          #+#    #+#             */
/*   Updated: 2023/03/25 11:13:48 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) && *(s2 + i)) && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
			i++;
		else if (*(s1 + i) > *(s2 + i) || *(s1 + i) < *(s2 + i))
			return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
	}
	if (n == i || (*(s1 + i) == 0 && *(s2 + i) == 0))
		return (0);
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

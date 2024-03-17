/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:13:03 by doukim            #+#    #+#             */
/*   Updated: 2023/03/16 17:42:33 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	idx;

	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		ret[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	return (ret);
}

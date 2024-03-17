/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:48:52 by doukim            #+#    #+#             */
/*   Updated: 2023/03/19 19:14:57 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			idx;
	const size_t	slen = ft_strlen(s);

	if (start > slen)
		len = 0;
	else if (start + len > slen)
		len = slen - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ret[idx] = s[start + idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

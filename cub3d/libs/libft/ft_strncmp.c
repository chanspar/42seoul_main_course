/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:51:39 by doukim            #+#    #+#             */
/*   Updated: 2023/03/13 19:01:11 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (!n)
		return (0);
	idx = 0;
	while (s1[idx] && s1[idx] == s2[idx] && idx + 1 < n)
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

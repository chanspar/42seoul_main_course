/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:17:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/04/11 20:21:55 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == 0)
		return ;
	s_len = ft_strlen(s);
	if (s_len <= 2147483647)
		write(fd, s, s_len);
	while (s_len > 2147483647)
	{
		write(fd, s, 2147483647);
		s_len -= 2147483647;
	}
	write(fd, "\n", 1);
}

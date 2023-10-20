/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:29:28 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/17 16:05:39 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_print(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	errno_print(char *str)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, " ", 1);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

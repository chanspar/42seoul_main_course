/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:09:31 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/08 20:48:57 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	a(void)
{
	system("leaks fdf");
}

int	main(int ac, char *av[])
{
	t_info	info;

	atexit(a);
	if (ac != 2)
		err_print("Usage : ./fdf <filename>");
	check_right_file(&info, av);
	mlx_utils(&info);
	draw_horizen(&info);
	draw_vertical(&info);
	event_exe(&info);
	return (0);
}

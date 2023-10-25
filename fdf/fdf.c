/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:09:31 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/25 14:05:19 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_key(int keycode, t_info *info)
{
	if (keycode == 53)
		mlx_destroy_window(info->mlx_pointer, info->win_pointer);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info	info;
	t_coord	coord;

	if (ac != 2)
		err_print("Usage : ./fdf <filename>");
	check_right_file(&info, &coord, av);
	get_coordinate(&info);
	projection(&info);
	for(int i=0; i<info.height;i++)
	{
		for(int j=0; j<info.width; j++)
			printf("%3d ", info.c_x[i][j]);
		printf("\n");
	}
	for(int i=0; i<info.height;i++)
	{
		for(int j=0; j<info.width; j++)
			printf("%3d ", info.c_y[i][j]);
		printf("\n");
	}
	info.mlx_pointer = mlx_init();
	info.win_pointer = mlx_new_window(info.mlx_pointer, 1920, 1080, "fdf");
	bresenham_exe1(&info, &coord);
	bresenham_exe2(&info, &coord);

	mlx_key_hook(info.win_pointer, close_key, 0); //seg fault뜸
	mlx_loop(info.mlx_pointer);
	
	return (0);
}

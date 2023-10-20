/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:09:31 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/20 12:49:11 by chanspar         ###   ########.fr       */
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

	if (ac != 2)
		err_print("Usage : ./fdf <filename>");
	check_right_file(&info, av);
	get_coordinate(&info);
	projection(&info);
	// for (int i=0; i<info.y; i++)
	// {
	// 	for (int j=0; j<info.x; j++)
	// 	{
	// 		printf("%3d ", info.y_prime[i][j]);
	// 	}
	// 	printf("\n");
	// }
	info.mlx_pointer = mlx_init();
	info.win_pointer = mlx_new_window(info.mlx_pointer, 1920, 1080, "fdf");
	for (int i=0; i<info.y; i++)
	{
		for (int j=0; j<info.x; j++)
		{
			mlx_pixel_put(info.mlx_pointer, info.win_pointer, info.c_x[i][j] + 960, info.c_y[i][j] + 540, 0xffffff);
		}
		printf("\n");
	}

	mlx_key_hook(info.win_pointer, close_key, 0); //seg fault뜸
	mlx_loop(info.mlx_pointer);
	
	return (0);
}

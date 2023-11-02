/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:01:39 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/02 18:33:14 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_info *info)
{
	mlx_destroy_image(info->p_mlx, info->p_img);
	mlx_destroy_window(info->p_mlx, info->p_win);
	exit(0);
}

int	close_key(int keycode, t_info *info)
{
	if (keycode == 53)
	{
		mlx_destroy_image(info->p_mlx, info->p_img);
		mlx_destroy_window(info->p_mlx, info->p_win);
		exit(0);
	}
	return (0);
}

void	event_exe(t_info *info)
{
	mlx_put_image_to_window(info->p_mlx, info->p_win, \
						info->p_img, 0, 0);
	mlx_hook(info->p_win, 2, 0L, close_key, info);
	mlx_hook(info->p_win, 17, 0L, close_win, info);
	mlx_loop(info->p_mlx);
}

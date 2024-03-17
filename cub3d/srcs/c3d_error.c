/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:20:11 by doukim            #+#    #+#             */
/*   Updated: 2024/03/16 18:21:18 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_err_exit(t_cub3d *info, char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	c3d_free_map_info(info);
	c3d_unload_texture(info);
	if (info->img)
	{
		if (info->img->img)
			mlx_destroy_image(info->mlx, info->img->img);
	}
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	exit(-1);
}

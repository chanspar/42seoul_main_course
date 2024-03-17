/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:31:20 by doukim            #+#    #+#             */
/*   Updated: 2024/03/15 10:30:08 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_init(t_cub3d *info)
{
	ft_memset(info, 0, sizeof(t_cub3d));
	info->map_info = (t_map *)malloc(sizeof(t_map));
	if (info->map_info == NULL)
		c3d_err_exit(info, "cub3D: malloc failed");
	ft_memset(info->map_info, 0, sizeof(t_map));
}

void	c3d_memeset_struct(t_cub3d *cub3d)
{
	ft_memset(cub3d->img, 0, sizeof(t_img));
	ft_memset(cub3d->press, 0, sizeof(t_press));
	ft_memset(cub3d->player, 0, sizeof(t_player));
	ft_memset(cub3d->ray, 0, sizeof(t_ray));
}

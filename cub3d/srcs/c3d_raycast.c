/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:12:46 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/15 09:32:55 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_step_init(t_cub3d *cub3d)
{
	if (cub3d->ray->raydir_x < 0)
	{
		cub3d->ray->step_x = -1;
		cub3d->ray->side_distx = (cub3d->player->pos_x - cub3d->ray->map_x) \
		* cub3d->ray->delta_distx;
	}
	else
	{
		cub3d->ray->step_x = 1;
		cub3d->ray->side_distx = (cub3d->ray->map_x + 1.0 - \
		cub3d->player->pos_x) * cub3d->ray->delta_distx;
	}
	if (cub3d->ray->raydir_y < 0)
	{
		cub3d->ray->step_y = -1;
		cub3d->ray->side_disty = (cub3d->player->pos_y - cub3d->ray->map_y) \
		* cub3d->ray->delta_disty;
	}
	else
	{
		cub3d->ray->step_y = 1;
		cub3d->ray->side_disty = (cub3d->ray->map_y + 1.0 - \
		cub3d->player->pos_y) * cub3d->ray->delta_disty;
	}
}

void	c3d_ray_init(t_cub3d *cub3d, int x)
{
	cub3d->ray->camera_x = 2 * x / (double)WIDTH - 1;
	cub3d->ray->raydir_x = cub3d->player->dir_x + cub3d->player->plane_x \
	* cub3d->ray->camera_x;
	cub3d->ray->raydir_y = cub3d->player->dir_y + cub3d->player->plane_y \
	* cub3d->ray->camera_x;
	cub3d->ray->map_x = (int)cub3d->player->pos_x;
	cub3d->ray->map_y = (int)cub3d->player->pos_y;
	if (cub3d->ray->raydir_x == 0)
		cub3d->ray->delta_distx = 1e32;
	else
		cub3d->ray->delta_distx = fabs(1 / cub3d->ray->raydir_x);
	if (cub3d->ray->raydir_y == 0)
		cub3d->ray->delta_disty = 1e32;
	else
		cub3d->ray->delta_disty = fabs(1 / cub3d->ray->raydir_y);
	c3d_step_init(cub3d);
	cub3d->ray->hit = 0;
}

void	c3d_dda(t_cub3d *cub3d)
{
	while (cub3d->ray->hit == 0)
	{
		if (cub3d->ray->side_distx < cub3d->ray->side_disty)
		{
			cub3d->ray->side_distx += cub3d->ray->delta_distx;
			cub3d->ray->map_x += cub3d->ray->step_x;
			cub3d->ray->side = 0;
			if (cub3d->ray->raydir_x < 0)
				cub3d->tex.num = 0;
			else
				cub3d->tex.num = 1;
		}
		else
		{
			cub3d->ray->side_disty += cub3d->ray->delta_disty;
			cub3d->ray->map_y += cub3d->ray->step_y;
			cub3d->ray->side = 1;
			if (cub3d->ray->raydir_y < 0)
				cub3d->tex.num = 2;
			else
				cub3d->tex.num = 3;
		}
		if (cub3d->map_info->map[cub3d->ray->map_y][cub3d->ray->map_x] == '1')
			cub3d->ray->hit = 1;
	}
}

void	c3d_perpwalldist(t_cub3d *cub3d)
{
	if (cub3d->ray->side == 0)
		cub3d->ray->perpwalldist = cub3d->ray->side_distx - \
		cub3d->ray->delta_distx;
	else
		cub3d->ray->perpwalldist = cub3d->ray->side_disty - \
		cub3d->ray->delta_disty;
}

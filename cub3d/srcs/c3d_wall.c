/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:29:47 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/15 10:28:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_cal_wall(t_cub3d *cub3d)
{
	cub3d->tex.wall_height = (int)(HEIGHT / cub3d->ray->perpwalldist);
	cub3d->tex.wall_start = -cub3d->tex.wall_height / 2 + HEIGHT / 2;
	if (cub3d->tex.wall_start < 0)
		cub3d->tex.wall_start = 0;
	cub3d->tex.wall_end = cub3d->tex.wall_height / 2 + HEIGHT / 2;
	if (cub3d->tex.wall_end >= HEIGHT)
		cub3d->tex.wall_end = HEIGHT - 1;
	if (cub3d->ray->side == 0)
		cub3d->tex.wall_x = cub3d->player->pos_y + \
		cub3d->ray->perpwalldist * cub3d->ray->raydir_y;
	else
		cub3d->tex.wall_x = cub3d->player->pos_x + \
		cub3d->ray->perpwalldist * cub3d->ray->raydir_x;
	cub3d->tex.wall_x -= floor(cub3d->tex.wall_x);
	cub3d->tex.x_coor = (int)(cub3d->tex.wall_x * (double)(cub3d->tex.width));
	if ((cub3d->ray->side == 0 && cub3d->ray->raydir_x < 0)
		|| (cub3d->ray->side == 1 && cub3d->ray->raydir_y > 0))
		cub3d->tex.x_coor = cub3d->tex.width - cub3d->tex.x_coor - 1;
}

int	c3d_cal_texture_color(t_texture *tex)
{
	int	color;

	color = 0x0;
	if (tex->x_coor >= 0 && tex->x_coor < tex->width
		&& tex->y_coor >= 0 && tex->y_coor < tex->height)
	{
		color = *(int *)(tex->wall[tex->num].addr + (4 * tex->width \
		* (int)tex->y_coor + (4 * (int)tex->x_coor)));
	}
	return (color);
}

void	c3d_draw_wall(t_cub3d *cub3d, int x)
{
	int	y;
	int	color;

	y = cub3d->tex.wall_start;
	cub3d->tex.step = 1.0 * cub3d->tex.height / cub3d->tex.wall_height;
	cub3d->tex.pos = (cub3d->tex.wall_start - HEIGHT / 2 \
	+ cub3d->tex.wall_height / 2) * cub3d->tex.step;
	while (y < cub3d->tex.wall_end)
	{
		cub3d->tex.y_coor = (int)cub3d->tex.pos & (cub3d->tex.height - 1);
		cub3d->tex.pos += cub3d->tex.step;
		color = c3d_cal_texture_color(&cub3d->tex);
		c3d_pixel_put(cub3d, x, y, color);
		y++;
	}
}

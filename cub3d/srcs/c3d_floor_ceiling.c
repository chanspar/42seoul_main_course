/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:42:12 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/15 02:21:52 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_pixel_put(t_cub3d *cub3d, int x, int y, int color)
{
	char	*pxl;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		pxl = cub3d->img->addr + (y * cub3d->img->size_l \
		+ x * (cub3d->img->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	c3d_cf_color(t_cub3d *cub3d)
{
	cub3d->ceiling_color = (cub3d->col_ceil->r << 16)
		| (cub3d->col_ceil->g << 8) | cub3d->col_ceil->b;
	cub3d->floor_color = (cub3d->col_floor->r << 16)
		| (cub3d->col_floor->g << 8) | cub3d->col_floor->b;
}

void	c3d_draw_cf(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				c3d_pixel_put(cub3d, x, y, cub3d->ceiling_color);
			else
				c3d_pixel_put(cub3d, x, y, cub3d->floor_color);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/25 13:23:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	incline_low(t_info *info, t_coord *coord, int dx, int dy)
{
	coord->k = 2 * dy - dx;
	coord->k_a = 2 * dy;
	coord->k_b = 2 * dy - dx;

	printf("incline low\n");
	while ((int)coord->x1 <= (int)coord->x2)
	{
		mlx_pixel_put(info->mlx_pointer, info->win_pointer, coord->x1 + 500 , coord->y1 + 200, 0xffffff);
		if (coord->k < 0)
			coord->k += coord->k_a;
		else
		{
			coord->k += coord->k_b;
			coord->y1 += coord->sy;
		}
		coord->x1 += coord->sx;
		// printf("%f %f\n", coord->x1, coord->x2);
	}
}

void	incline_high(t_info *info, t_coord *coord, int dx, int dy)
{
	coord->k = 2 * dx - dy;
	coord->k_a = 2 * dx;
	coord->k_b = 2 * dx - dy;

	printf("incline high\n");
	while ((int)coord->y1 <= (int)coord->y2)
	{
		mlx_pixel_put(info->mlx_pointer, info->win_pointer, coord->x1 + 500 , coord->y1 + 200, 0xffffff);
		if (coord->k < 0)
			coord->k += coord->k_a;
		else
		{
			coord->k += coord->k_b;
			coord->x1 += coord->sx;
		}
		coord->y1 += coord->sy;
		// printf("%f %f\n", coord->y1, coord->y2);

	}
}

void	bresenham(t_info *info, t_coord *coord)
{
	int	dx;
	int	dy;

	dx = (int)fabs(coord->x2 - coord->x1);
	dy = (int)fabs(coord->y2 - coord->y1);
	if (coord->x1 <= coord->x2)
		coord->sx = 1;
	else
		coord->sx = -1;
	if (coord->y1 <= coord->y2)
		coord->sy = 1;
	else
		coord->sy = -1;
	if (dx >= dy)
		incline_low(info, coord, dx, dy);
	else
		incline_high(info, coord, dx, dy);
}

void	draw(t_info *info, t_coord *coord)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height - 1)
	{
		x = 0;
		while (x < info->width - 1)
		{
			horizen(info, coord, x, y);
			printf("x1 : %f y1 : %f\n", coord->x1, coord->y1);
			printf("x2 : %f y2 : %f\n", coord->x2, coord->y2);
			bresenham(info, coord);
			vertical(info, coord, x, y);
			bresenham(info, coord);
			x++;
		}
		y++;
	}
}
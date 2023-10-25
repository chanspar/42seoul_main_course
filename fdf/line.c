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
	while ((int)coord->x1 <= (int)coord->x2)
	{
		mlx_pixel_put(info->mlx_pointer, info->win_pointer, coord->x1 + 860 , coord->y1 + 400, 0xffffff);
		if (coord->k < 0)
			coord->k += coord->k_a;
		else
		{
			coord->k += coord->k_b;
			coord->y1 += coord->sy;
		}
		coord->x1 += coord->sx;
	}
}

void	incline_high(t_info *info, t_coord *coord, int dx, int dy)
{
	coord->k = 2 * dx - dy;
	coord->k_a = 2 * dx;
	coord->k_b = 2 * dx - dy;
	while ((int)coord->y1 <= (int)coord->y2)
	{
		mlx_pixel_put(info->mlx_pointer, info->win_pointer, coord->x1 + 860 , coord->y1 + 400, 0xffffff);
		if (coord->k < 0)
			coord->k += coord->k_a;
		else
		{
			coord->k += coord->k_b;
			coord->x1 += coord->sx;
		}
		coord->y1 += coord->sy;
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

void	bresenham_exe1(t_info *info, t_coord *coord)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width - 1)
		{
			coord->x1 = info->c_x[i][j];
			coord->y1 = info->c_y[i][j];
			coord->x2 = info->c_x[i][j + 1];
			coord->y2 = info->c_y[i][j + 1];
			bresenham(info, coord);
			j++;
		}
		i++;
	}
}

void	bresenham_exe2(t_info *info, t_coord *coord)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height - 1)
	{
		j = 0;
		while (j < info->width)
		{
			coord->x1 = info->c_x[i][j];
			coord->y1 = info->c_y[i][j];
			coord->x2 = info->c_x[i + 1][j];
			coord->y2 = info->c_y[i + 1][j];
			bresenham(info, coord);
			j++;
		}
		i++;
	}
}

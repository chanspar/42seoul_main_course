/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:08:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/08 21:18:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xaxis_rotate(t_coord *coord, double theta)
{
	double	ay;
	double	az;

	ay = coord->y;
	az = coord->z;
	coord->y = ay * cos(theta) + az * sin(theta);
	coord->z = -ay * sin(theta) + az * cos(theta);
}

void	yaxis_rotate(t_coord *coord, double theta)
{
	double	ax;
	double	az;

	ax = coord->x;
	az = coord->z;
	coord->x = ax * cos(theta) - (az * sin(theta));
	coord->z = ax * sin(theta) + az * cos(theta);
}

void	draw_horizen(t_info *info)
{
	int		i;
	int		j;
	t_coord	s;
	t_coord	f;

	j = 0;
	while (j < info->height)
	{
		i = 0;
		while (i < info->width - 1)
		{
			s.color = info->color[j][i];
			s.x = (info->x[j][i] + abs_int(info->min_x)) * info->gap + MARGIN;
			s.y = (info->y[j][i] + abs_int(info->min_y)) * info->gap + MARGIN;
			f.x = (info->x[j][i + 1] + abs_int(info->min_x)) * info->gap;
			f.y = (info->y[j][i + 1] + abs_int(info->min_y)) * info->gap;
			f.x += MARGIN;
			f.y += MARGIN;
			bresenham(info, &s, &f);
			i++;
		}
		j++;
	}
}

void	draw_vertical(t_info *info)
{
	int		i;
	int		j;
	t_coord	s;
	t_coord	f;

	j = 0;
	while (j < info->height - 1)
	{
		i = 0;
		while (i < info->width)
		{
			s.color = info->color[j][i];
			s.x = (info->x[j][i] + abs_int(info->min_x)) * info->gap + MARGIN;
			s.y = (info->y[j][i] + abs_int(info->min_y)) * info->gap + MARGIN;
			f.x = (info->x[j + 1][i] + abs_int(info->min_x)) * info->gap;
			f.y = (info->y[j + 1][i] + abs_int(info->min_y)) * info->gap;
			f.x += MARGIN;
			f.y += MARGIN;
			bresenham(info, &s, &f);
			i++;
		}
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:08:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/25 14:14:58 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	xaxis_rotate(t_coord *coord, double theta)
{
	double	ax;
	double	ay;
	double	az;

	ax = coord->x1;
	ay = coord->y1;
	az = coord->z1;
	coord->x1 = ax;
	coord->y1 = (ay * cos(theta) + (az * sin(theta) * -1));
	coord->z1 = (ay * sin(theta) + az * cos(theta));
	ax = coord->x2;
	ay = coord->y2;
	az = coord->z2;
	coord->x2 = ax;
	coord->y2 = (ay * cos(theta) + (az * sin(theta) * -1));
	coord->z2 = (ay * sin(theta) + az * cos(theta));
}

void	yaxis_rotate(t_coord *coord, double theta)
{
	double	ax;
	double	ay;
	double	az;

	ax = coord->x1;
	ay = coord->y1;
	az = coord->z1;
	// printf("%f %f\n", ax, ay);
	coord->x1 = (ax * cos(theta) + (az * sin(theta) * -1));
	coord->y1 = ay;
	coord->z1 = (ax * sin(theta) + az * cos(theta));
	// printf("%f %f\n", coord->x1, coord->y1);
	ax = coord->x2;
	ay = coord->y2;
	az = coord->z2;
	coord->x2 = (ax * cos(theta) + (az * sin(theta) * -1));
	coord->y2 = ay;
	coord->z2 = (ax * sin(theta) + az * cos(theta));
}

void	horizen(t_info *info, t_coord *coord, int x, int y)
{
	coord->x1 = x;
	coord->y1 = y;
	coord->x2 = x + 1;
	coord->y2 = y;
	coord->z1 = info->z[y][x];
	coord->z2 = info->z[y][x + 1];
	yaxis_rotate(coord, 45 * M_PI / 180);
	xaxis_rotate(coord, 35.264 * M_PI / 180);
	coord->x1 *= info->gap;
	coord->x2 *= info->gap;
	coord->y1 *= info->gap;
	coord->y2 *= info->gap;
}

void	vertical(t_info *info, t_coord *coord, int x, int y)
{
	coord->x1 = x;
	coord->y1 = y;
	coord->x2 = x;
	coord->y2 = y + 1;
	coord->z1 = info->z[y][x];
	coord->z2 = info->z[y + 1][x];
	yaxis_rotate(coord, 45 * M_PI / 180);
	xaxis_rotate(coord, 35.264 * M_PI / 180);
	coord->x1 *= info->gap;
	coord->x2 *= info->gap;
	coord->y1 *= info->gap;
	coord->y2 *= info->gap;
}
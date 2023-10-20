/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:08:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/20 13:27:01 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xaxis_rotate(t_info *info, double theta)
{
	int		ay;
	int		az;
	int		i;
	int		j;
	double	t;

	i = 0;
	t = theta * M_PI / 180;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			ay = info->c_y[i][j];
			az = info->z[i][j];
			info->c_y[i][j] = ay * cos(t) + az * sin(t);
			info->z[i][j] = -ay * sin(t) + az * cos(t);
			j++;
		}
		i++;
	}
}

void	yaxis_rotate(t_info *info, double theta)
{
	int		ax;
	int		az;
	int		i;
	int		j;
	double	t;

	i = 0;
	t = theta * M_PI / 180;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			ax = info->c_x[i][j];
			az = info->z[i][j];
			info->c_x[i][j] = ax * cos(t) - az * sin(t);
			info->z[i][j] = ax * sin(t) + az * cos(t);
			j++;
		}
		i++;
	}
}

void	projection(t_info *info)
{
	xaxis_rotate(info, 45);
	yaxis_rotate(info, 35.264);
}

void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->y)
	{
		x = 0;
		while (x < info->x)
		{

			x++;
		}
		y++;
	}
}

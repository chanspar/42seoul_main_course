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

void	xaxis_rotate(t_info *info, double theta)
{
	double	ay;
	double	az;
	int		i;
	int		j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			ay = info->c_y[i][j];
			az = info->z[i][j];
			info->c_y[i][j] = ay * cos(theta) + az * sin(theta);
			info->z[i][j] = -ay * sin(theta) + az * cos(theta);
			j++;
		}
		i++;
	}
}

void	yaxis_rotate(t_info *info, double theta)
{
	double	ax;
	double	az;
	int		i;
	int		j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			ax = info->c_x[i][j];
			az = info->z[i][j];
			info->c_x[i][j] = ax * cos(theta) - az * sin(theta);
			info->z[i][j] = ax * sin(theta) + az * cos(theta);
			j++;
		}
		i++;
	}
}

void	projection(t_info *info)
{
	int	i;
	int	j;

	yaxis_rotate(info, 45 * M_PI / 180);
	xaxis_rotate(info, 35.264 * M_PI / 180);
	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			info->c_x[i][j] *= info->gap;
			info->c_y[i][j] *= info->gap;
			j++;
		}
		i++;
	}
}

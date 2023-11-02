/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:08:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/02 18:27:17 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xaxis_rotate(t_coord *coord, double theta)
{
	int	ay;
	int	az;

	ay = coord->y;
	az = coord->z;
	coord->y = ay * cos(theta) + az * sin(theta);
	coord->z = -ay * sin(theta) + az * cos(theta);
}

void	yaxis_rotate(t_coord *coord, double theta)
{
	int	ax;
	int	az;

	ax = coord->x;
	az = coord->z;
	coord->x = ax * cos(theta) - (az * sin(theta));
	coord->z = ax * sin(theta) + az * cos(theta);
}

// void	zaxis_rotate(t_coord *coord, double theta)
// {
// 	int	ax;
// 	int	ay;

// 	ax = coord->x;
// 	ay = coord->y;
// 	coord->x = ax * cos(theta) + ay * sin(theta);
// 	coord->y = -ax * sin(theta) + ay * cos(theta);
// }

void	draw_horizen(t_info *info)
{
	int		x;
	int		y;
	t_coord	start;
	t_coord	final;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width - 1)
		{
			horizen(&start, &final, x, y);
			z_parse(info, &start, &final);

			// yaxis_rotate(&start, -10 * M_PI / 180);
			// yaxis_rotate(&final, -10 * M_PI / 180);

			// xaxis_rotate(&start, -50 * M_PI / 180);
			// xaxis_rotate(&final, -50 * M_PI / 180);

			bresenham(info, &start, &final);
			x++;
		}
		y++;
	}
}

void	draw_vertical(t_info *info)
{
	int		x;
	int		y;
	t_coord	start;
	t_coord	final;

	y = 0;
	while (y < info->height - 1)
	{
		x = 0;
		while (x < info->width)
		{
			vertical(&start, &final, x, y);
			z_parse(info, &start, &final);

			// yaxis_rotate(&start, -10 * M_PI / 180);
			// yaxis_rotate(&final, -10 * M_PI / 180);

			// xaxis_rotate(&start, -50 * M_PI / 180);
			// xaxis_rotate(&final, -50 * M_PI / 180);


			bresenham(info, &start, &final);
			x++;
		}
		y++;
	}
}

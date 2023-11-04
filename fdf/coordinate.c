/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/04 12:43:16 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_min(t_info *info, t_coord *coord)
{
	if (info->max_x < coord->x)
		info->max_x = coord->x;
	if (info->max_y < coord->y)
		info->max_y = coord->y;
	if (info->min_x > coord->x)
		info->min_x = coord->x;
	if (info->min_y > coord->y)
		info->min_y = coord->y;
}

void	get_gap(t_info *info)
{
	info->gap = 1;
	while (((info->max_x - info->min_x) * info->gap + 2 * MARGIN) < MAX_WIDTH
		&& ((info->max_y - info->min_y) * info->gap + 2 * MARGIN) < MAX_HEIGHT)
		info->gap++;
	if (info->gap > 30)
		info->gap = 30;
	if (info->gap != 1)
		info->gap--;
}

void	get_xy(t_info *info)
{
	t_coord	coord;
	int		i;
	int		j;

	j = 0;
	while (j < info->height)
	{
		i = 0;
		while (i < info->width)
		{
			coord.x = i;
			coord.y = j;
			coord.z = info->z[j][i];
			xaxis_rotate(&coord, -M_PI / 2);
			yaxis_rotate(&coord, M_PI / 4);
			xaxis_rotate(&coord, M_PI / 180 * 38);
			info->x[j][i] = coord.x;
			info->y[j][i] = coord.y;
			get_max_min(info, &coord);
			i++;
		}
		j++;
	}
	get_gap(info);
}

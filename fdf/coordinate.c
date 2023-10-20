/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/20 03:25:16 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**make_two_dim(t_info *info)
{
	int	i;
	int	**coord;

	coord = (int **)malloc(sizeof(int *) * info->y);
	if (coord == 0)
		err_print("malloc fail");
	i = 0;
	while (i < info->y)
	{
		coord[i] = (int *)malloc(sizeof(int) * info->x);
		if (coord[i] == 0)
			err_print("malloc fail");
		i++;
	}
	return (coord);
}

void	get_xcoord(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			info->c_x[i][j] = j * info->gap;
			j++;
		}
		i++;
	}
}

void	get_ycoord(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			info->c_y[i][j] = i * info->gap;
			j++;
		}
		i++;
	}
}

void	get_zcoord(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			info->z[i][j] = info->z[i][j] * info->gap;
			j++;
		}
		i++;
	}
}

void	get_coordinate(t_info *info)
{
	info->gap = 22;
	while ((info->x * info->gap) > 2200 || (info->y * info->gap) > 1400)
		info->gap--;
	info->c_x = make_two_dim(info);
	info->c_y = make_two_dim(info);
	get_xcoord(info);
	get_ycoord(info);
	get_zcoord(info);
	info->x_prime = make_two_dim(info);
	info->y_prime = make_two_dim(info);
}

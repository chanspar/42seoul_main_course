/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:47:45 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/08 20:07:33 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**make_two_dim(t_info *info)
{
	int	i;
	int	j;
	int	**coord;

	coord = (int **)malloc(sizeof(int *) * info->height);
	if (coord == 0)
		err_print("malloc fail");
	i = 0;
	while (i < info->height)
	{
		coord[i] = (int *)malloc(sizeof(int) * info->width);
		if (coord[i] == 0)
			err_print("malloc fail");
		j = 0;
		while (j < info->width)
		{
			coord[i][j] = 0;
			j++;
		}
		i++;
	}
	return (coord);
}

double	**make_two_dim_d(t_info *info)
{
	int		i;
	int		j;
	double	**coord;

	coord = (double **)malloc(sizeof(double *) * info->height);
	if (coord == 0)
		err_print("malloc fail");
	i = 0;
	while (i < info->height)
	{
		coord[i] = (double *)malloc(sizeof(double) * info->width);
		if (coord[i] == 0)
			err_print("malloc fail");
		j = 0;
		while (j < info->width)
		{
			coord[i][j] = 0;
			j++;
		}
		i++;
	}
	return (coord);
}

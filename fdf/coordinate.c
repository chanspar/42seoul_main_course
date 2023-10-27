/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/24 19:23:36 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**make_two_dim(t_info *info)
{
	int	i;
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
		i++;
	}
	return (coord);
}

void	get_coordinate(t_info *info)
{
	info->gap = 20;
	while ((info->width * info->gap) > 2200 || (info->height * info->gap) > 1400)
		info->gap--;
	// info->c_x = make_two_dim(info);
	// info->c_y = make_two_dim(info);
	// get_xcoord(info);
	// get_ycoord(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/02 17:54:36 by chanspar         ###   ########.fr       */
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

void	horizen(t_coord *s, t_coord *f, int x, int y)
{
	s->x = x;
	s->y = y;
	f->x = x + 1;
	f->y = y;
}

void	vertical(t_coord *s, t_coord *f, int x, int y)
{
	s->x = x;
	s->y = y;
	f->x = x;
	f->y = y + 1;
}

void	z_parse(t_info *info, t_coord *s, t_coord *f)
{
	s->color = info->color[s->y][s->x];
	f->color = info->color[f->y][f->x];
	s->z = info->z[s->y][s->x] * info->gap;
	f->z = info->z[f->y][f->x] * info->gap;
	s->x *= info->gap;
	s->y *= info->gap;
	f->x *= info->gap;
	f->y *= info->gap;
}

void	get_gap(t_info *info)
{
	info->gap = 20;
	while ((info->width * info->gap) > WIDTH
		|| (info->height * info->gap) > HEIGHT)
		info->gap--;
	if (info->gap <= 0)
		info->gap = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:40:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/04 10:10:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs_int(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	incline_low(t_info *info, t_coord *cur, t_coord *final, int dx_dy[2])
{
	int	k;
	int	cur_x;
	int	cur_y;
	int	cur_color;
	int	step;

	cur_x = cur->x;
	cur_y = cur->y;
	cur_color = cur->color;
	step = abs_int((int)final->x - cur_x);
	k = 2 * dx_dy[1] - dx_dy[0];
	while (cur_x != (int)final->x)
	{
		if (k < 0)
			k += 2 * dx_dy[1];
		else
		{
			k += 2 * (dx_dy[1] - dx_dy[0]);
			cur_y += cur->sx_sy[1];
		}
		cur_x += cur->sx_sy[0];
		decide_color(cur, final, &cur_color, step);
		my_pixel_put(info, cur_x, cur_y, cur_color);
	}
}

void	incline_high(t_info *info, t_coord *cur, t_coord *final, int dx_dy[2])
{
	int	k;
	int	cur_x;
	int	cur_y;
	int	cur_color;
	int	step;

	cur_x = cur->x;
	cur_y = cur->y;
	cur_color = cur->color;
	step = abs_int((int)final->y - cur_y);
	k = 2 * dx_dy[0] - dx_dy[1];
	while (cur_y != (int)final->y)
	{
		if (k < 0)
			k += 2 * dx_dy[0];
		else
		{
			k += 2 * (dx_dy[0] - dx_dy[1]);
			cur_x += cur->sx_sy[0];
		}
		cur_y += cur->sx_sy[1];
		decide_color(cur, final, &cur_color, step);
		my_pixel_put(info, cur_x, cur_y, cur_color);
	}
}

void	get_sx_sy(t_coord *start, t_coord *final, t_coord *cur)
{
	if (start->x <= final->x)
		cur->sx_sy[0] = 1;
	else
		cur->sx_sy[0] = -1;
	if (start->y <= final->y)
		cur->sx_sy[1] = 1;
	else
		cur->sx_sy[1] = -1;
}

void	bresenham(t_info *info, t_coord *start, t_coord *final)
{
	int		dx_dy[2];
	t_coord	*cur;

	cur = start;
	my_pixel_put(info, cur->x, cur->y, cur->color);
	dx_dy[0] = abs_int(final->x - start->x);
	dx_dy[1] = abs_int(final->y - start->y);
	get_sx_sy(start, final, cur);
	if (dx_dy[0] > dx_dy[1])
		incline_low(info, cur, final, dx_dy);
	else
		incline_high(info, cur, final, dx_dy);
}

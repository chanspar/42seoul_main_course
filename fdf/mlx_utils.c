/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:30:51 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/04 09:06:25 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_window_size(t_info *info)
{
	info->win_x = (info->max_x - info->min_x) * info->gap + 2 * (MARGIN + 10);
	info->win_y = (info->max_y - info->min_y) * info->gap + 2 * (MARGIN + 10);
	if (info->win_x > MAX_WIDTH)
		info->win_x = MAX_WIDTH;
	if (info->win_y > MAX_HEIGHT)
		info->win_y = MAX_HEIGHT;
}

void	mlx_utils(t_info *info)
{
	info->p_mlx = mlx_init();
	if (!info->p_mlx)
		err_print("fail mlx");
	info->p_win = mlx_new_window(info->p_mlx, info->win_x, info->win_y, "fdf");
	if (!info->p_win)
		err_print("fail mlx");
	info->p_img = mlx_new_image(info->p_mlx, info->win_x, info->win_y);
	if (!info->p_img)
		err_print("fail mlx");
	info->addr = mlx_get_data_addr(info->p_img \
						, &info->bpp, &info->l_l, &info->ed);
}

void	my_pixel_put(t_info *info, int x, int y, int color)
{
	int				pixel_offset;
	unsigned int	*pixel_addr;

	if ((x >= 0 && x <= info->win_x) && (y >= 0 && y <= info->win_y))
	{
		pixel_offset = (y * info->l_l) + (x * (info->bpp / 8));
		pixel_addr = (unsigned int *)(info->addr + pixel_offset);
		*pixel_addr = color;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:30:51 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/02 18:36:05 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_utils(t_info *info)
{
	info->p_mlx = mlx_init();
	if (!info->p_mlx)
		err_print("fail mlx");
	info->p_win = mlx_new_window(info->p_mlx, WIDTH, HEIGHT, "fdf");
	if (!info->p_win)
		err_print("fail mlx");
	info->p_img = mlx_new_image(info->p_mlx, WIDTH, HEIGHT);
	if (!info->p_img)
		err_print("fail mlx");
	info->addr = mlx_get_data_addr(info->p_img \
						, &info->bpp, &info->l_l, &info->ed);
}

void	my_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->l_l + x * (info->bpp / 8));
	*(unsigned int *) dst = color;
}

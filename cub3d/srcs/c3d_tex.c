/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:10:53 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/15 11:14:13 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_split_load_texture(t_cub3d *cub3d)
{
	cub3d->tex.wall[0].img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->tex_we, \
	&cub3d->tex.width, &cub3d->tex.height);
	if (cub3d->tex.wall[0].img == 0)
		c3d_err_exit(cub3d, "fail to get image");
	cub3d->tex.wall[0].addr = mlx_get_data_addr(cub3d->tex.wall[0].img, \
	&cub3d->tex.wall[0].bpp, &cub3d->tex.wall[0].size_l, \
	&cub3d->tex.wall[0].endian);
	cub3d->tex.wall[1].img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->tex_ea, \
	&cub3d->tex.width, &cub3d->tex.height);
	if (cub3d->tex.wall[1].img == 0)
		c3d_err_exit(cub3d, "fail to get image");
	cub3d->tex.wall[1].addr = mlx_get_data_addr(cub3d->tex.wall[1].img, \
	&cub3d->tex.wall[1].bpp, &cub3d->tex.wall[1].size_l, \
	&cub3d->tex.wall[1].endian);
}

void	c3d_load_texture(t_cub3d *cub3d)
{
	c3d_split_load_texture(cub3d);
	cub3d->tex.wall[2].img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->tex_no, \
	&cub3d->tex.width, &cub3d->tex.height);
	if (cub3d->tex.wall[2].img == 0)
		c3d_err_exit(cub3d, "fail to get image");
	cub3d->tex.wall[2].addr = mlx_get_data_addr(cub3d->tex.wall[2].img, \
	&cub3d->tex.wall[2].bpp, &cub3d->tex.wall[2].size_l, \
	&cub3d->tex.wall[2].endian);
	cub3d->tex.wall[3].img = mlx_xpm_file_to_image(cub3d->mlx, cub3d->tex_so, \
	&cub3d->tex.width, &cub3d->tex.height);
	if (cub3d->tex.wall[3].img == 0)
		c3d_err_exit(cub3d, "fail to get image");
	cub3d->tex.wall[3].addr = mlx_get_data_addr(cub3d->tex.wall[3].img, \
	&cub3d->tex.wall[3].bpp, &cub3d->tex.wall[3].size_l, \
	&cub3d->tex.wall[3].endian);
}

void	c3d_unload_texture(t_cub3d *cub3d)
{
	if (cub3d->tex.wall[0].img)
		mlx_destroy_image(cub3d->mlx, cub3d->tex.wall[0].img);
	if (cub3d->tex.wall[1].img)
		mlx_destroy_image(cub3d->mlx, cub3d->tex.wall[1].img);
	if (cub3d->tex.wall[2].img)
		mlx_destroy_image(cub3d->mlx, cub3d->tex.wall[2].img);
	if (cub3d->tex.wall[3].img)
		mlx_destroy_image(cub3d->mlx, cub3d->tex.wall[3].img);
}

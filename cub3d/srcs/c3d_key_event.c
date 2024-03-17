/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:30:14 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/16 17:15:26 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_clear_img(t_cub3d *cub3d)
{
	if (cub3d->img->img)
		mlx_destroy_image(cub3d->mlx, cub3d->img->img);
	cub3d->img->img = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->img->img)
		c3d_err_exit(cub3d, "cub3D: malloc failed\n");
	cub3d->img->addr = mlx_get_data_addr(cub3d->img->img, \
		&cub3d->img->bpp, &cub3d->img->size_l, &cub3d->img->endian);
}

int	c3d_key_hook(t_cub3d *cub3d)
{
	if (cub3d->press->key_w || cub3d->press->key_s \
	|| cub3d->press->key_a || cub3d->press->key_d \
	|| cub3d->press->key_l || cub3d->press->key_r)
	{
		c3d_move_player(cub3d);
		c3d_rotate_player(cub3d);
	}
	return (0);
}

int	c3d_key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W)
		cub3d->press->key_w = 1;
	if (keycode == KEY_A)
		cub3d->press->key_a = 1;
	if (keycode == KEY_S)
		cub3d->press->key_s = 1;
	if (keycode == KEY_D)
		cub3d->press->key_d = 1;
	if (keycode == L_ARROW)
		cub3d->press->key_l = 1;
	if (keycode == R_ARROW)
		cub3d->press->key_r = 1;
	if (keycode == KEY_ESC)
		c3d_free_end(cub3d);
	return (0);
}

int	c3d_key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == KEY_W)
		cub3d->press->key_w = 0;
	if (keycode == KEY_A)
		cub3d->press->key_a = 0;
	if (keycode == KEY_S)
		cub3d->press->key_s = 0;
	if (keycode == KEY_D)
		cub3d->press->key_d = 0;
	if (keycode == L_ARROW)
		cub3d->press->key_l = 0;
	if (keycode == R_ARROW)
		cub3d->press->key_r = 0;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:10:50 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/13 20:14:29 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_rotate_left(t_cub3d *cub3d)
{
	double		temp_dirx;
	double		temp_planex;
	t_player	*player;

	player = cub3d->player;
	temp_dirx = player->dir_x;
	temp_planex = player->plane_x;
	player->dir_x = player->dir_y * sin(player->rotate_speed) \
	+ player->dir_x * cos(player->rotate_speed);
	player->dir_y = player->dir_y * cos(player->rotate_speed) \
	- temp_dirx * sin(player->rotate_speed);
	player->plane_x = player->plane_y * sin(player->rotate_speed) \
	+ player->plane_x * cos(player->rotate_speed);
	player->plane_y = player->plane_y * cos(player->rotate_speed) \
	- temp_planex * sin(player->rotate_speed);
}

void	c3d_rotate_right(t_cub3d *cub3d)
{
	double		temp_dirx;
	double		temp_planex;
	t_player	*player;

	player = cub3d->player;
	temp_dirx = player->dir_x;
	temp_planex = player->plane_x;
	player->dir_x = player->dir_x * cos(player->rotate_speed) \
	- player->dir_y * sin(player->rotate_speed);
	player->dir_y = temp_dirx * sin(player->rotate_speed) \
	+ player->dir_y * cos(player->rotate_speed);
	player->plane_x = player->plane_x * cos(player->rotate_speed) \
	- player->plane_y * sin(player->rotate_speed);
	player->plane_y = temp_planex * sin(player->rotate_speed) \
	+ player->plane_y * cos(player->rotate_speed);
}

void	c3d_rotate_player(t_cub3d *cub3d)
{
	if (cub3d->press->key_r && !cub3d->press->key_l)
		c3d_rotate_right(cub3d);
	if (cub3d->press->key_l && !cub3d->press->key_r)
		c3d_rotate_left(cub3d);
}

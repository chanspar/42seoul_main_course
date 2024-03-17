/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:52 by chanspar          #+#    #+#             */
/*   Updated: 2024/02/13 19:54:52 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_move_forward(t_cub3d *cub3d)
{
	char		**world_map;
	t_player	*player;

	world_map = cub3d->map_info->map;
	player = cub3d->player;
	if (world_map[(int)(player->pos_y)][(int)(player->pos_x + player->dir_x * \
	player->move_speed)] == '0')
		player->pos_x += player->dir_x * player->move_speed;
	if (world_map[(int)(player->pos_y + \
	player->dir_y * player->move_speed)][(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_y * player->move_speed;
}

void	c3d_move_back(t_cub3d *cub3d)
{
	char		**world_map;
	t_player	*player;

	world_map = cub3d->map_info->map;
	player = cub3d->player;
	if (world_map[(int)(player->pos_y)][(int)(player->pos_x - player->dir_x * \
	player->move_speed)] == '0')
		player->pos_x -= player->dir_x * player->move_speed;
	if (world_map[(int)(player->pos_y - \
	player->dir_y * player->move_speed)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_y * player->move_speed;
}

void	c3d_move_left(t_cub3d *cub3d)
{
	char		**world_map;
	t_player	*player;

	world_map = cub3d->map_info->map;
	player = cub3d->player;
	if (world_map[(int)(player->pos_y)][(int)(player->pos_x + player->dir_y * \
	player->move_speed)] == '0')
		player->pos_x += player->dir_y * player->move_speed;
	if (world_map[(int)(player->pos_y - \
	player->dir_x * player->move_speed)][(int)(player->pos_x)] == '0')
		player->pos_y -= player->dir_x * player->move_speed;
}

void	c3d_move_right(t_cub3d *cub3d)
{
	char		**world_map;
	t_player	*player;

	world_map = cub3d->map_info->map;
	player = cub3d->player;
	if (world_map[(int)(player->pos_y)][(int)(player->pos_x - player->dir_y * \
	player->move_speed)] == '0')
		player->pos_x -= player->dir_y * player->move_speed;
	if (world_map[(int)(player->pos_y + \
	player->dir_x * player->move_speed)][(int)(player->pos_x)] == '0')
		player->pos_y += player->dir_x * player->move_speed;
}

void	c3d_move_player(t_cub3d *cub3d)
{
	if (cub3d->press->key_w && !cub3d->press->key_s)
		c3d_move_forward(cub3d);
	if (cub3d->press->key_s && !cub3d->press->key_w)
		c3d_move_back(cub3d);
	if (cub3d->press->key_a && !cub3d->press->key_d)
		c3d_move_left(cub3d);
	if (cub3d->press->key_d && !cub3d->press->key_a)
		c3d_move_right(cub3d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:26:20 by doukim            #+#    #+#             */
/*   Updated: 2024/03/16 18:12:43 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = tmp2;
	}
	*list = NULL;
	return ;
}

void	c3d_free_map_info(t_cub3d *info)
{
	int	idx;

	if (info->map_info->map != NULL)
	{
		idx = 0;
		while (idx < info->map_info->height)
		{
			if (info->map_info->map[idx] != NULL)
				free(info->map_info->map[idx]);
			idx++;
		}
		free(info->map_info->map);
		info->map_info->map = NULL;
	}
	if (info->map_info != NULL)
		free(info->map_info);
}

void	c3d_free_end(t_cub3d *info)
{
	free(info->filename);
	c3d_free_map_info(info);
	c3d_unload_texture(info);
	if (info->img)
	{
		if (info->img->img)
			mlx_destroy_image(info->mlx, info->img->img);
	}
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	free(info->img);
	free(info->press);
	free(info->player);
	free(info->ray);
	exit(0);
}

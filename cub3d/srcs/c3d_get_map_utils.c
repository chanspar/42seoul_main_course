/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:46:35 by chanspar          #+#    #+#             */
/*   Updated: 2024/03/15 10:59:20 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_skip_one_word(char **line)
{
	while (*line && (**line == ' ' || (9 <= **line && **line <= 13)))
		(*line)++;
	while (*line && !(**line == ' ' || (9 <= **line && **line <= 13)))
		(*line)++;
	while (*line && (**line == ' ' || (9 <= **line && **line <= 13)))
		(*line)++;
}

void	c3d_chk_row_valid(t_cub3d *info, char **map)
{
	int	x;
	int	y;
	int	inside;

	x = -1;
	while (++x < info->map_info->height)
	{
		inside = 0;
		y = -1;
		while (++y < info->map_info->width)
		{
			if (inside == 0 && map[x][y] == '1')
				inside = 1;
			if (inside == 0 && (map[x][y] != ' ' && map[x][y] != '1'))
				c3d_err_exit(info, "cub3D: invalid map format");
			if (inside == 1 && map[x][y] == '1' && \
			(y + 1 == info->map_info->width || map[x][y + 1] == ' '))
				inside = 0;
			if (inside == 1 && map[x][y] == ' ')
				c3d_err_exit(info, "cub3D: invalid map format");
		}
		if (inside)
			c3d_err_exit(info, "cub3D: invalid map format");
	}
}

void	c3d_chk_col_valid(t_cub3d *info, char **map)
{
	int	x;
	int	y;
	int	inside;

	x = -1;
	while (++x < info->map_info->width)
	{
		inside = 0;
		y = -1;
		while (++y < info->map_info->height)
		{
			if (inside == 0 && map[y][x] == '1')
				inside = 1;
			if (inside == 0 && (map[y][x] != ' ' && map[y][x] != '1'))
				c3d_err_exit(info, "cub3D: invalid map format");
			if (inside == 1 && map[y][x] == '1' && \
			(y + 1 == info->map_info->height || map[y + 1][x] == ' '))
				inside = 0;
			if (inside == 1 && map[y][x] == ' ')
				c3d_err_exit(info, "cub3D: invalid map format");
		}
		if (inside)
			c3d_err_exit(info, "cub3D: invalid map format");
	}
}

void	c3d_chk_field_valid_err(t_cub3d *info, char **map, int x, int y)
{
	if (ft_strchr("01 NSWE", map[x][y]) == NULL)
		c3d_err_exit(info, "cub3D: invalid map format");
}

void	c3d_chk_field_valid(t_cub3d *info, char **map)
{
	int		x;
	int		y;

	info->start_dir = 0;
	x = -1;
	while (++x < info->map_info->height)
	{
		y = -1;
		while (++y < info->map_info->width)
		{
			if (map[x][y] == 'N' || map[x][y] == 'E' \
			|| map[x][y] == 'W' || map[x][y] == 'S')
			{
				if (info->start_dir != 0)
					c3d_err_exit(info, "cub3D: invalid map format");
				info->start_dir = map[x][y];
				info->start_locx = y;
				info->start_locy = x;
				map[x][y] = '0';
			}
			c3d_chk_field_valid_err(info, map, x, y);
		}
	}
	if (info->start_dir == 0)
		c3d_err_exit(info, "cub3D: invalid map format");
}

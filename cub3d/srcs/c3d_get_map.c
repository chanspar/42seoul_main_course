/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:34:05 by doukim            #+#    #+#             */
/*   Updated: 2024/03/16 18:25:26 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_get_map_resource(t_cub3d *info, int file_fd)
{
	int		cnt;
	char	*line;
	void	**resource_ptr;

	cnt = 0;
	while (cnt < 6)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			c3d_err_exit(info, "cub3D: failed to read file");
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		resource_ptr = c3d_get_resource_type(info, line);
		if (resource_ptr == NULL || *resource_ptr != NULL)
			c3d_err_exit(info, "cub3D: invalid resource format");
		c3d_get_proper_resource(info, resource_ptr, line);
		free(line);
		cnt++;
	}
}

void	c3d_get_map_shape(t_cub3d *info, int file_fd)
{
	t_list	*maplist;

	maplist = NULL;
	c3d_get_listmap(info, file_fd, &maplist);
	c3d_cvt_dblptrmap(info, maplist);
	c3d_free_list(&maplist);
}

void	c3d_chk_map_valid(t_cub3d *info)
{
	c3d_chk_row_valid(info, info->map_info->map);
	c3d_chk_col_valid(info, info->map_info->map);
	c3d_chk_field_valid(info, info->map_info->map);
}

void	c3d_get_map(t_cub3d *info)
{
	int		file_fd;

	file_fd = open(info->filename, O_RDONLY);
	if (file_fd == -1)
		c3d_err_exit(info, "cub3D: failed to open file");
	c3d_get_map_resource(info, file_fd);
	c3d_get_map_shape(info, file_fd);
	c3d_chk_map_valid(info);
	close(file_fd);
}

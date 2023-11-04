/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:03:52 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/04 14:38:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_right_file(t_info *info, char *av[])
{
	int		len;

	ft_memset(info, 0, sizeof(t_info));
	info->max_x = -9999999;
	info->max_y = -9999999;
	info->min_x = 9999999;
	info->min_y = 9999999;
	len = ft_strlen(av[1]);
	if (len < 4 || ft_strncmp(av[1] + len - 4, ".fdf", 4) != 0)
		errno_print(av[1]);
	map_parse(info, av);
	get_xy(info);
	get_window_size(info);
}

int	get_width(char *file)
{
	int		fd;
	int		x;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		errno_print(file);
	line = get_next_line(fd);
	if (line == 0)
		errno_print(file);
	x = word_cnt1(line, ' ');
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (x > word_cnt1(line, ' '))
			err_print("Found wrong line length. Exiting.");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (x);
}

int	get_height(char *file)
{
	int		fd;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		errno_print(file);
	while (get_next_line(fd))
		y++;
	close(fd);
	return (y);
}

void	get_z(t_info *info, char *file, int i, int j)
{
	int		fd;
	char	*line;
	char	**tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		errno_print(file);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_split(line, ' ');
		i = 0;
		while (tmp[i])
		{
			info->z[j][i] = ft_atoi(tmp[i]);
			get_color(info, tmp[i], i, j);
			free(tmp[i]);
			i++;
		}
		free(tmp);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	close(fd);
}

void	map_parse(t_info *info, char *av[])
{
	int	i;
	int	j;

	info->width = get_width(av[1]);
	info->height = get_height(av[1]);
	info->x = make_two_dim_d(info);
	info->y = make_two_dim_d(info);
	info->z = make_two_dim(info);
	info->color = make_two_dim(info);
	i = 0;
	j = 0;
	get_z(info, av[1], i, j);
}

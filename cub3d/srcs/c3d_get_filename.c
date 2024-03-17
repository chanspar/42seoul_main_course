/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:16:18 by doukim            #+#    #+#             */
/*   Updated: 2024/03/15 10:35:37 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_get_filename(t_cub3d *info, int argc, char *argv[])
{
	int	filename_len;

	if (argc != 2)
		c3d_err_exit(info, "cub3D: only 1 argument required!\n");
	filename_len = ft_strlen(argv[1]);
	if (filename_len < 5 || ft_strncmp(argv[1] + (filename_len - 4), ".cub", 4))
		c3d_err_exit(info, "cub3D: invalid filename format!\n");
	info->filename = ft_strdup(argv[1]);
	return ;
}

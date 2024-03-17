/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:20:22 by doukim            #+#    #+#             */
/*   Updated: 2024/03/16 18:26:00 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void a()
{
	system("leaks --list cub3D");
}

int	main(int argc, char *argv[])
{
	t_cub3d	info;

	atexit(a);
	c3d_init(&info);
	c3d_get_filename(&info, argc, argv);
	c3d_get_map(&info);
	c3d_mlx_init(&info);
	c3d_event_exe(&info);
}

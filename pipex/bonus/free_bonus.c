/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:31:33 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/10 21:26:52 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_cmd(t_info *info)
{
	int	i;

	i = 0;
	if (info->cmds != 0)
	{
		while (info->cmds[i] != 0)
		{
			free(info->cmds[i]);
			i++;
		}
		free(info->cmds);
	}
	if (info->cmds_path != 0)
		free(info->cmds_path);
}

void	free_others(t_info *info, int ac)
{
	int	i;

	i = 0;
	if (info->fds != 0)
	{
		while (i < ac - 4)
		{
			free(info->fds[i]);
			i++;
		}
		free(info->fds);
	}
	i = 0;
	if (info->path != 0)
	{
		while (info->path[i] != 0)
		{
			free(info->path[i]);
			i++;
		}
		free(info->path);
	}
	if (info->pids != 0)
		free(info->pids);
}

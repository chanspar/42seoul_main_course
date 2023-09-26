/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:31:33 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/25 20:49:24 by chanspar         ###   ########.fr       */
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

void	free_cmd1(t_info *info)
{
	int	i;

	i = 0;
	if (info->cmd1 != 0)
	{
		while (info->cmd1[i] != 0)
		{
			free(info->cmd1[i]);
			i++;
		}
		free(info->cmd1);
	}
	if (info->cmd_path1 != 0)
		free(info->cmd_path1);
}

void	free_cmd_last(t_info *info)
{
	int	i;

	i = 0;
	if (info->cmd2 != 0)
	{
		while (info->cmd2[i] != 0)
		{
			free(info->cmd2[i]);
			i++;
		}
		free(info->cmd2);
	}
	if (info->cmd_path2 != 0)
		free(info->cmd_path2);
}

void	free_others(t_info *info)
{
	int	i;

	i = 0;
	if (info->fds != 0)
	{
		while (info->fds[i] != 0)
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
	free(info->path);
	free(info->pids);
}

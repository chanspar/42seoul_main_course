/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/25 19:56:46 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_utils(t_info *info)
{
	int	i;

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
	if (info->cmd_path1 != 0)
		free(info->cmd_path1);
	if (info->cmd_path2 != 0)
		free(info->cmd_path2);
}

void	free_struct(t_info *info)
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
	free_utils(info);
}

int	main(int ac, char *av[], char *envp[])
{
	t_info	info;

	if (ac != 5)
	{
		write(1, "number of argument error\n", 25);
		exit(1);
	}
	input_info(&info, av, envp);
	process1(&info);
	free_struct(&info);
	return (0);
}

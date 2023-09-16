/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/16 11:29:10 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_info *info)
{
	int	i;

	i = 0;
	while (info->cmd1[i])
	{
		free(info->cmd1[i]);
		i++;
	}
	free(info->cmd1);
	i = 0;
	while (info->cmd2[i])
	{
		free(info->cmd2[i]);
		i++;
	}
	i = 0;
	while (info->path[i])
	{
		free(info->path[i]);
		i++;
	}
	free(info->cmd2);
	free(info->cmd_path1);
	free(info->cmd_path2);
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

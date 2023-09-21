/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:45:21 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/21 21:28:16 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *envp[], t_info *info)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			cmd_path = ft_strdup(envp[i] + 5);
			if (cmd_path == 0)
				err_print("Memory allocation fail", info);
			return (cmd_path);
		}
		i++;
	}
	return (0);
}

char	**path_list(t_info *info)
{
	char	*envp_path;
	char	**tmp;

	envp_path = find_path(info->envp, info);
	if (envp_path == 0)
		err_print("not found path", info);
	tmp = ft_split(envp_path, ':');
	free(envp_path);
	if (tmp == 0)
		err_print("Memory allocation fail", info);
	return (tmp);
}

void	input_info(t_info *info, char *av[], char *envp[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->infile = av[1];
	info->outfile = av[4];
	info->infile_fd = open(av[1], O_RDWR);
	info->outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	info->envp = envp;
	info->path = path_list(info);
	if (ft_strncmp(av[2], "", ft_strlen(av[2])) != 0)
	{
		info->cmd1 = ft_split(av[2], ' ');
		if (info->cmd1 == 0)
			err_print("Memory allocation fail", info);
		info->cmd_path1 = merge_cmd(info->path, info->cmd1, info);
	}
	if (ft_strncmp(av[3], "", ft_strlen(av[3])) != 0)
	{
		info->cmd2 = ft_split(av[3], ' ');
		if (info->cmd2 == 0)
			err_print("Memory allocation fail", info);
		info->cmd_path2 = merge_cmd(info->path, info->cmd2, info);
	}
}

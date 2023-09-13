/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:45:21 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/13 21:26:22 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *envp[])
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
				err_print("Memory allocation fail");
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

	envp_path = find_path(info->envp);
	if (envp_path == 0)
		err_print("not found path");
	tmp = ft_split(envp_path, ':');
	free(envp_path);
	if (tmp == 0)
		err_print("Memory allocation fail");
	return (tmp);
}

char	*merge_cmd(char **env_path, char **cmd)
{
	int		i;
	char	*cmd_tmp;
	char	*tmp;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	if (ft_strncmp(cmd[0], "/", 1) == 0
		|| ft_strncmp(cmd[0], "./", 2) == 0)
		err_print_s("no such file or directory: ", cmd[0]);
	cmd_tmp = ft_strjoin("/", cmd[0]);
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], cmd_tmp);
		if (access(tmp, X_OK) == 0)
		{
			free(cmd_tmp);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(cmd_tmp);
	return (0);
}

void	input_info(t_info *info, char *av[], char *envp[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->infile_fd = open(av[1], O_RDWR);
	if (info->infile_fd == -1)
		errno_print("infile error");
	info->outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd == -1)
		errno_print("outfile error");
	info->cmd1 = ft_split(av[2], ' ');
	if (info->cmd1 == 0)
		err_print("Memory allocation fail");
	info->cmd2 = ft_split(av[3], ' ');
	if (info->cmd2 == 0)
		err_print("Memory allocation fail");
	info->envp = envp;
	info->path = path_list(info);
	info->cmd_path1 = merge_cmd(info->path, info->cmd1);
	if (info->cmd_path1 == 0)
		err_print_s("command not found: ", info->cmd1[0]);
	info->cmd_path2 = merge_cmd(info->path, info->cmd2);
	if (info->cmd_path2 == 0)
		err_print_s("command not found: ", info->cmd2[0]);
}

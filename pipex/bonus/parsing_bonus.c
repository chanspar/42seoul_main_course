/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:11:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/10 17:30:36 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path_b(char *envp[], t_info *info)
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
				err_print_b("Memory allocation fail", info);
			return (cmd_path);
		}
		i++;
	}
	return (0);
}

char	**path_list_b(t_info *info)
{
	char	*envp_path;
	char	**tmp;

	envp_path = find_path_b(info->envp, info);
	if (envp_path == 0)
		err_print_b("not found path", info);
	tmp = ft_split(envp_path, ':');
	free(envp_path);
	if (tmp == 0)
		err_print_b("Memory allocation fail", info);
	return (tmp);
}

void	make_cmd(t_info *info, char *av[], int idx)
{
	if (ft_strncmp(av[idx + 2], "", ft_strlen(av[idx + 2])) != 0)
	{
		info->cmds = ft_split(av[idx + 2], ' ');
		if (info->cmds == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmds[0] != 0)
			info->cmds_path = merge_cmd_b(info->path, info->cmds, info);
	}
}

void	input_info_b(t_info *info, int ac, char *av[], char *envp[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->infile = av[1];
	info->outfile = av[ac - 1];
	info->infile_fd = open(av[1], O_RDONLY);
	info->outfile_fd = open(av[ac -1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	info->envp = envp;
	info->path = path_list_b(info);
}

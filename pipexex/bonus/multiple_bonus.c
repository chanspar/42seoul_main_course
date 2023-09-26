/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:10:35 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/26 16:17:39 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_mp(t_info *info, char *av[], int idx)
{
	if (ft_strncmp(av[idx + 1], "", ft_strlen(av[idx + 1])) != 0)
	{
		info->cmds = ft_split(av[idx + 1], ' ');
		if (info->cmds == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmds[0] != 0)
			info->cmds_path = merge_cmd_b(info->path, info->cmds, info);
	}
	if (info->cmds == 0)
		err_print_b("pipex: permission denied: ", info);
	if (info->cmds[0] == 0)
		err_print_b("pipex: command not found: ", info);
	if (check_slash_b(info->cmds) == 1 && access(info->cmds[0], X_OK) != 0)
		err_print_s_b("no such file or directory: ", info->cmds[0], info);
	if (info->cmds_path == 0)
		err_print_s_b("command not found: ", info->cmds[0], info);
}

void	process_mp(t_info *info, int ac, int idx)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		if (i != idx)
			close(info->fds[i][1]);
		i++;
	}
	i = 0;
	while (i < ac -4)
	{
		if (i != idx - 1)
			close(info->fds[i][0]);
		i++;
	}
	close(info->infile_fd);
	close(info->outfile_fd);
	dup2_check_b(info->fds[idx - 1][0], 0);
	dup2_check_b(info->fds[idx][1], 1);
	close(info->fds[idx - 1][0]);
	close(info->fds[idx][1]);
	if (execve(info->cmds_path, info->cmds, info->envp) == -1)
		errno_print_b("Execve fail", info);
}

void	parent_mp(t_info *info, int ac, int status, int i)
{
	i = 0;
	while (i < ac - 4)
	{
		close(info->fds[i][1]);
		i++;
	}
	i = 0;
	while (i < ac -4)
	{
		close(info->fds[i][0]);
		i++;
	}
	close(info->infile_fd);
	close(info->outfile_fd);
	i = 0;
	while (i < ac - 4)
	{
		if (waitpid(info->pids[i], 0, 0) == -1)
			errno_print_b("fail wait", info);
		i++;
	}
	if (waitpid(info->pids[i], &status, 0) == -1)
		errno_print_b("fail wait", info);
	if (WEXITSTATUS(status) != 0)
		exit(1);
}

void	mp_utils(t_info *info, int ac, char *av[], int i)
{
	info->pids[i] = fork();
	if (info->pids[i] == -1)
		errno_print_b("fork fail", info);
	else if (info->pids[i] == 0)
	{
		if (i == 0)
		{
			check_cmd1(info, av);
			process_first(info, ac);
			free_cmd1(info);
		}
		else if (i == ac - 4)
		{	
			check_cmd_last(info, av, i);
			process_last(info, ac, i);
			free_cmd_last(info);
		}
		else
		{
			check_mp(info, av, i);
			process_mp(info, ac, i);
			free_cmd(info);
		}
	}
}

void	multie_process(t_info *info, int ac, char *av[])
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	make_pid_fork(info, ac);
	while (i < ac - 4)
	{
		if (pipe(info->fds[i]) == -1)
			errno_print_b("pipe fail", info);
		i++;
	}
	i = 0;
	while (i < ac - 3)
	{
		mp_utils(info, ac, av, i);
		i++;
	}
	parent_mp(info, ac, status, i);
}

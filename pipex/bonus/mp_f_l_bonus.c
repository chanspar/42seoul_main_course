/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_f_l_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:39:25 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/10 21:08:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_cmd1(t_info *info)
{
	if (info->infile_fd == -1)
	{
		if (access(info->infile, F_OK) == -1)
			errno_print_b(info->infile, info);
		else if (access(info->infile, R_OK) == -1)
			errno_print_b(info->infile, info);
		else
			errno_print_b(info->infile, info);
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

void	check_cmd_last(t_info *info)
{
	if (info->outfile_fd == -1)
	{
		if (access(info->outfile, F_OK) == -1)
			errno_print_b(info->outfile, info);
		else if (access(info->outfile, R_OK | W_OK) == -1)
			errno_print_b(info->outfile, info);
		else
			errno_print_b(info->outfile, info);
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

void	process_first(t_info *info, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		close_fd_b(info->fds[i][0], info);
		i++;
	}
	i = 1;
	while (i < ac - 4)
	{
		close_fd_b(info->fds[i][1], info);
		i++;
	}
	close_fd_b(info->outfile_fd, info);
	dup2_check_b(info->infile_fd, 0);
	dup2_check_b(info->fds[0][1], 1);
	close_fd_b(info->fds[0][1], info);
	close_fd_b(info->infile_fd, info);
	if (execve(info->cmds_path, info->cmds, info->envp) == -1)
		errno_print_b("Execve fail", info);
}

void	process_last(t_info *info, int ac, int idx)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		close_fd_b(info->fds[i][1], info);
		i++;
	}
	i = 0;
	while (i < ac - 5)
	{
		close_fd_b(info->fds[i][0], info);
		i++;
	}
	close_fd_b(info->infile_fd, info);
	dup2_check_b(info->outfile_fd, 1);
	dup2_check_b(info->fds[idx - 1][0], 0);
	close_fd_b(info->fds[idx - 1][0], info);
	close_fd_b(info->outfile_fd, info);
	if (execve(info->cmds_path, info->cmds, info->envp) == -1)
		errno_print_b("Execve fail", info);
}

void	make_pid_fork(t_info *info, int ac)
{
	int	i;

	i = 0;
	info->pids = (int *)malloc(sizeof(int) * (ac - 3));
	if (info->pids == 0)
		err_print_b("Memory allocation fail", info);
	info->fds = (int **)malloc(sizeof(int *) * (ac - 4));
	if (info->fds == 0)
		err_print_b("Memory allocation fail", info);
	while (i < ac - 4)
	{
		info->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (info->fds[i] == 0)
			err_print_b("Memory allocation fail", info);
		i++;
	}
}

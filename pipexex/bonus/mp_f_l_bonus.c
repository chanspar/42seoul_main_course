/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_f_l_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:39:25 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/26 16:16:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_cmd1(t_info *info, char *av[])
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
	if (ft_strncmp(av[2], "", ft_strlen(av[2])) != 0)
	{
		info->cmd1 = ft_split(av[2], ' ');
		if (info->cmd1 == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmd1[0] != 0)
			info->cmd_path1 = merge_cmd_b(info->path, info->cmd1, info);
	}
	if (info->cmd1 == 0)
		err_print_b("pipex: permission denied: ", info);
	if (info->cmd1[0] == 0)
		err_print_b("pipex: command not found: ", info);
	if (check_slash_b(info->cmd1) == 1 && access(info->cmd1[0], X_OK) != 0)
		err_print_s_b("no such file or directory: ", info->cmd1[0], info);
	if (info->cmd_path1 == 0)
		err_print_s_b("command not found: ", info->cmd1[0], info);
}

void	check_cmd_last(t_info *info, char *av[], int idx)
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
	if (ft_strncmp(av[idx + 1], "", ft_strlen(av[idx + 1])) != 0)
	{
		info->cmd2 = ft_split(av[idx + 1], ' ');
		if (info->cmd2 == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmd2[0] != 0)
			info->cmd_path2 = merge_cmd_b(info->path, info->cmd2, info);
	}
	if (info->cmd2 == 0)
		err_print_b("pipex: permission denied: ", info);
	if (info->cmd2[0] == 0)
		err_print_b("pipex: command not found: ", info);
	if (check_slash_b(info->cmd2) == 1 && access(info->cmd2[0], X_OK) != 0)
		err_print_s_b("no such file or directory: ", info->cmd2[0], info);
	if (info->cmd_path2 == 0)
		err_print_s_b("command not found: ", info->cmd2[0], info);
}

void	process_first(t_info *info, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		close(info->fds[i][0]);
		i++;
	}
	i = 1;
	while (i < ac - 4)
	{
		close(info->fds[i][1]);
		i++;
	}
	close(info->outfile_fd);
	dup2_check_b(info->infile_fd, 0);
	dup2_check_b(info->fds[0][1], 1);
	close(info->fds[0][1]);
	close(info->infile_fd);
	if (execve(info->cmd_path1, info->cmd1, info->envp) == -1)
		errno_print_b("Execve fail", info);
}

void	process_last(t_info *info, int ac, int idx)
{
	int	i;

	i = 0;
	while (i < ac - 4)
	{
		close(info->fds[i][1]);
		i++;
	}
	i = 0;
	while (i < ac - 5)
	{
		close(info->fds[i][0]);
		i++;
	}
	close(info->infile_fd);
	dup2_check_b(info->outfile_fd, 1);
	dup2_check_b(info->fds[idx][0], 0);
	close(info->fds[idx][0]);
	close(info->outfile_fd);
	if (execve(info->cmd_path2, info->cmd2, info->envp) == -1)
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

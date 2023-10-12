/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:38:41 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/26 22:27:24 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process1_util(t_info *info)
{
	if (info->infile_fd == -1)
	{
		if (access(info->infile, F_OK) == -1)
			errno_print(info->infile, info);
		else if (access(info->infile, R_OK) == -1)
			errno_print(info->infile, info);
		else
			errno_print(info->infile, info);
	}
	if (info->cmd1 == 0)
		err_print("pipex: permission denied: ", info);
	if (info->cmd1[0] == 0)
		err_print("pipex: command not found: ", info);
	if (check_slash(info->cmd1) == 1 && access(info->cmd1[0], X_OK) != 0)
		err_print_s("no such file or directory: ", info->cmd1[0], info);
	if (info->cmd_path1 == 0)
		err_print_s("command not found: ", info->cmd1[0], info);
}

void	process2_util(t_info *info)
{
	if (info->outfile_fd == -1)
	{
		if (access(info->outfile, F_OK) == -1)
			errno_print(info->outfile, info);
		else if (access(info->outfile, R_OK | W_OK) == -1)
			errno_print(info->outfile, info);
		else
			errno_print(info->outfile, info);
	}
	if (info->cmd2 == 0)
		err_print("pipex: permission denied: ", info);
	if (info->cmd2[0] == 0)
		err_print("pipex: command not found: ", info);
	if (check_slash(info->cmd2) == 1 && access(info->cmd2[0], X_OK) != 0)
		err_print_s("no such file or directory: ", info->cmd2[0], info);
	if (info->cmd_path2 == 0)
		err_print_s("command not found: ", info->cmd2[0], info);
}

void	process1(t_info *info)
{
	if (pipe(info->fd) < 0)
		errno_print("pipe fail", info);
	info->pid1 = fork();
	if (info->pid1 == -1)
		errno_print("fork fail", info);
	else if (info->pid1 == 0)
	{
		process1_util(info);
		close_fd(info, info->fd[0]);
		close_fd(info, info->outfile_fd);
		dup2_check(info->infile_fd, 0);
		dup2_check(info->fd[1], 1);
		close_fd(info, info->fd[1]);
		close_fd(info, info->infile_fd);
		if (execve(info->cmd_path1, info->cmd1, info->envp) == -1)
			errno_print("Execve fail", info);
	}
	process2(info);
}

void	process2(t_info *info)
{
	info->pid2 = fork();
	if (info->pid2 == -1)
		errno_print("fork fail", info);
	else if (info->pid2 == 0)
	{
		process2_util(info);
		close_fd(info, info->fd[1]);
		close_fd(info, info->infile_fd);
		dup2_check(info->fd[0], 0);
		dup2_check(info->outfile_fd, 1);
		close_fd(info, info->fd[0]);
		close_fd(info, info->outfile_fd);
		if (execve(info->cmd_path2, info->cmd2, info->envp) == -1)
			errno_print("Execve fail", info);
	}
	process3(info);
}

void	process3(t_info *info)
{
	int	status;
	int	sleep;

	sleep = 0;
	while (sleep < 100000)
		sleep++;
	close_fd(info, info->fd[0]);
	close_fd(info, info->fd[1]);
	close_fd(info, info->infile_fd);
	close_fd(info, info->outfile_fd);
	if (waitpid(info->pid1, 0, 0) == -1)
		errno_print("fail wait", info);
	if (waitpid(info->pid2, &status, 0) == -1)
		errno_print("fail wait", info);
	if (WEXITSTATUS(status) != 0)
		exit(1);
}

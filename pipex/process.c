/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 03:38:41 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/16 11:13:16 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process1(t_info *info)
{
	if (pipe(info->fd) < 0)
		errno_print("pipe fail", info);
	info->pid1 = fork();
	if (info->pid1 == -1)
		errno_print("fork fail", info);
	else if (info->pid1 == 0)
	{
		if (info->infile_fd == -1)
			errno_print(info->infile, info);
		if (check_slash(info->cmd1) == 1)
			err_print_s("no such file or directory: ", info->cmd1[0], info);
		if (info->cmd_path1 == 0)
			err_print_s("command not found: ", info->cmd1[0], info);
		close_fd(info->fd[0]);
		close_fd(info->outfile_fd);
		dup2_check(info->infile_fd, STDIN_FILENO);
		dup2_check(info->fd[1], STDOUT_FILENO);
		close_fd(info->fd[1]);
		close_fd(info->infile_fd);
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
		if (info->outfile_fd == -1)
			errno_print(info->outfile, info);
		if (check_slash(info->cmd2) == 1)
			err_print_s("no such file or directory: ", info->cmd2[0], info);
		if (info->cmd_path2 == 0)
			err_print_s("command not found: ", info->cmd2[0], info);
		close_fd(info->fd[1]);
		close_fd(info->infile_fd);
		dup2_check(info->fd[0], STDIN_FILENO);
		dup2_check(info->outfile_fd, STDOUT_FILENO);
		close_fd(info->fd[0]);
		close_fd(info->outfile_fd);
		if (execve(info->cmd_path2, info->cmd2, info->envp) == -1)
			errno_print("Execve fail", info);
	}
	process3(info);
}

void	process3(t_info *info)
{
	close_fd(info->fd[0]);
	close_fd(info->fd[1]);
	if (info->infile_fd != -1)
		close_fd(info->infile_fd);
	if (info->outfile_fd != -1)
		close_fd(info->outfile_fd);
	waitpid(info->pid1, NULL, 0);
	waitpid(info->pid2, NULL, 0);
}

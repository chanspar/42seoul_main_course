/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:11:22 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/26 16:15:22 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	process_c1_util(t_info *info)
{
	if (info->cmd1 == 0)
		err_print_hd("pipex: permission denied: ", info);
	if (info->cmd1[0] == 0)
		err_print_hd("pipex: command not found: ", info);
	if (check_slash_b(info->cmd1) == 1 && access(info->cmd1[0], X_OK) != 0)
		err_print_s_hd("no such file or directory: ", info->cmd1[0], info);
	if (info->cmd_path1 == 0)
		err_print_s_hd("command not found: ", info->cmd1[0], info);
}

void	process_c2_util(t_info *info)
{
	if (info->outfile_fd == -1)
	{
		if (access(info->outfile, F_OK) == -1)
			errno_print_hd(info->outfile, info);
		else if (access(info->outfile, R_OK) == -1)
			errno_print_hd(info->outfile, info);
		else
			errno_print_hd(info->outfile, info);
	}
	if (info->cmd2 == 0)
		err_print_hd("pipex: permission denied: ", info);
	if (info->cmd2[0] == 0)
		err_print_hd("pipex: command not found: ", info);
	if (check_slash_b(info->cmd2) == 1 && access(info->cmd2[0], X_OK) != 0)
		err_print_s_hd("no such file or directory: ", info->cmd2[0], info);
	if (info->cmd_path2 == 0)
		err_print_s_hd("command not found: ", info->cmd2[0], info);
}

void	process_c1(t_info *info)
{
	if (pipe(info->fd) < 0)
		errno_print_hd("pipe fail", info);
	info->pid1 = fork();
	if (info->pid1 == -1)
		errno_print_hd("fork fail", info);
	info->temp_fd = make_temp(info);
	if (info->temp_fd == -1)
		err_print_hd("fail to make file", info);
	else if (info->pid1 == 0)
	{
		input_stream(info);
		process_c1_util(info);
		close_fd_b(info->fd[0]);
		close_fd_b(info->outfile_fd);
		dup2_check_b(info->temp_fd, 0);
		dup2_check_b(info->fd[1], 1);
		close_fd_b(info->temp_fd);
		close_fd_b(info->fd[1]);
		if (execve(info->cmd_path1, info->cmd1, info->envp) == -1)
			errno_print_hd("Execve fail", info);
	}
	process_c2(info);
}

void	process_c2(t_info *info)
{
	info->pid2 = fork();
	if (info->pid2 == -1)
		errno_print_hd("fork fail", info);
	else if (info->pid2 == 0)
	{
		process_c2_util(info);
		close_fd_b(info->fd[1]);
		close_fd_b(info->temp_fd);
		dup2_check_b(info->fd[0], 0);
		dup2_check_b(info->outfile_fd, 1);
		close_fd_b(info->fd[0]);
		close_fd_b(info->outfile_fd);
		if (execve(info->cmd_path2, info->cmd2, info->envp) == -1)
			errno_print_hd("Execve fail", info);
	}
}

void	process_p(t_info *info)
{
	int	status;

	close_fd_b(info->fd[0]);
	close_fd_b(info->fd[1]);
	close_fd_b(info->outfile_fd);
	close_fd_b(info->temp_fd);
	if (waitpid(info->pid1, 0, 0) == -1)
		errno_print_hd("fail wait", info);
	if (waitpid(info->pid2, &status, 0) == -1)
		errno_print_hd("fail wait", info);
	if (unlink(info->temp) == -1)
		errno_print_hd("fail unlink", info);
	free(info->temp);
	if (WEXITSTATUS(status) != 0)
		exit(1);
}

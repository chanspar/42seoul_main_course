/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/13 22:41:15 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	connect_pipe(t_info *info)
{
	if (pipe(info->fd) < 0)
		errno_print("pipe fail");
	info->pid = fork();
	if (info->pid == -1)
		errno_print("fork fail");
	else if (info->pid == 0)
	{
		dup2_check(info->infile_fd, STDIN_FILENO);
		dup2_check(info->fd[1], STDOUT_FILENO);
		close_fd(info->fd[0]);
		close_fd(info->fd[1]);
		close_fd(info->infile_fd);
		if (execve(info->cmd_path1, info->cmd1, info->envp) == -1)
			errno_print("Execve fail");
	}
	dup2_check(info->fd[0], STDIN_FILENO);
	dup2_check(info->outfile_fd, STDOUT_FILENO);
	close_fd(info->fd[1]);
	close_fd(info->fd[0]);
	close_fd(info->outfile_fd);
	waitpid(info->pid, NULL, WNOHANG);
	if (execve(info->cmd_path2, info->cmd2, info->envp) == -1)
		errno_print("Execve fail");
}

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
		err_print("number of argument error");
	input_info(&info, av, envp);
	connect_pipe(&info);
	free_struct(&info);
	return (0);
}

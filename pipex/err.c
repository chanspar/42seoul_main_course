/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:43:51 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/16 11:24:25 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errno_print(char *str, t_info *info)
{
	if (info->infile_fd != -1)
		close_fd(info->infile_fd);
	if (info->outfile_fd != -1)
		close_fd(info->outfile_fd);
	if (info->fd[0])
		close_fd(info->fd[0]);
	if (info->fd[1])
		close_fd(info->fd[1]);
	write(1, "pipex: ", 7);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, ": ", 2);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	err_print(char *str, t_info *info)
{
	if (info->infile_fd != -1)
		close_fd(info->infile_fd);
	if (info->outfile_fd != -1)
		close_fd(info->outfile_fd);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	err_print_s(char *str1, char *str2, t_info *info)
{
	if (info->infile_fd != -1)
		close_fd(info->infile_fd);
	if (info->outfile_fd != -1)
		close_fd(info->outfile_fd);
	if (info->fd[0])
		close_fd(info->fd[0]);
	if (info->fd[1])
		close_fd(info->fd[1]);
	write(1, "pipex: ", 7);
	write(1, str1, ft_strlen(str1));
	write(1, str2, ft_strlen(str2));
	write(1, "\n", 1);
	exit(1);
}

void	close_fd(int fildes)
{
	if (close(fildes) == -1)
		exit(1);
}

void	dup2_check(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit(1);
}

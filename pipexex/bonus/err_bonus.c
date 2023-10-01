/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:15:29 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/24 16:37:31 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	errno_print_b(char *str, t_info *info)
{
	if (info->infile_fd != -1)
		close(info->infile_fd);
	if (info->outfile_fd != -1)
		close(info->outfile_fd);
	if (info->fd[0])
		close(info->fd[0]);
	if (info->fd[1])
		close(info->fd[1]);
	write(2, "pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	err_print_b(char *str, t_info *info)
{
	if (info->infile_fd != -1)
		close(info->infile_fd);
	if (info->outfile_fd != -1)
		close(info->outfile_fd);
	if (info->fd[0])
		close(info->fd[0]);
	if (info->fd[1])
		close(info->fd[1]);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	err_print_s_b(char *str1, char *str2, t_info *info)
{
	if (info->infile_fd != -1)
		close(info->infile_fd);
	if (info->outfile_fd != -1)
		close(info->outfile_fd);
	if (info->fd[0])
		close(info->fd[0]);
	if (info->fd[1])
		close(info->fd[1]);
	write(2, "pipex: ", 7);
	write(2, str1, ft_strlen(str1));
	write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
	exit(1);
}

void	dup2_check_b(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		exit(1);
}

void	close_fd_b(t_info *info, int fdfd)
{
	if (fdfd >= 0)
	{
		if (close(fdfd) == -1)
			errno_print_hd("close fail", info);
	}
}

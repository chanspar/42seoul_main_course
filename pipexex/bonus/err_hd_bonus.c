
#include "pipex_bonus.h"

void	errno_print_hd(char *str, t_info *info)
{
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

void	err_print_hd(char *str, t_info *info)
{
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

void	err_print_s_hd(char *str1, char *str2, t_info *info)
{
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
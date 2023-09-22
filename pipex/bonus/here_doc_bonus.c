/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:35:08 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 22:39:29 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_info(t_info *info, char *av[], char *envp[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->tag = av[2];
	info->outfile = av[5];
	info->outfile_fd = open(av[5], O_RDWR | O_CREAT | O_TRUNC, 0644);
	info->envp = envp;
	info->path = path_list_b(info);
	if (ft_strncmp(av[3], "", ft_strlen(av[3])) != 0)
	{
		info->cmd1 = ft_split(av[2], ' ');
		if (info->cmd1 == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmd1[0] != 0)
			info->cmd_path1 = merge_cmd_b(info->path, info->cmd1, info);
	}
	if (ft_strncmp(av[4], "", ft_strlen(av[4])) != 0)
	{
		info->cmd2 = ft_split(av[3], ' ');
		if (info->cmd2 == 0)
			err_print_b("Memory allocation fail", info);
		if (info->cmd2[0] != 0)
			info->cmd_path2 = merge_cmd_b(info->path, info->cmd2, info);
	}
}

int	make_temp(t_info *info)
{
	int		fd;
	int		tries;
	char	*tmp;

	tries = 10;
	while (tries > 0)
	{
		fd = open(info->temp, O_RDWR | O_CREAT, 0644);
		if (fd != -1)
			return (fd);
		tmp = info->temp;
		info->temp = ft_strjoin(info->temp, "_123");
		free(tmp);
		if (info->temp == 0)
			err_print_b("Memory allocation fail", info);
		tries--;
	}
	return (-1);
}

void	input_stream(t_info *info)
{
	char	*line;

	info->temp = ft_strdup("mytempfile");
	if (info->temp == 0)
		err_print_b("Memory allocation fail", info);
	info->temp_fd = make_temp(info);
	if (info->temp_fd == -1)
		err_print_b("fail to make file", info);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!ft_strncmp(info->tag, line, ft_strlen(info->tag)) || !line)
			break ;
		write(info->temp_fd, line, ft_strlen(line));
		free(line);
	}
	//close(info->temp_fd);
	//free(info->temp);
}

void	process_c1(t_info *info)
{
	if (pipe(info->fd) < 0)
		errno_print_b("pipe fail", info);
	info->pid1 = fork();
	if (info->pid1 == -1)
		errno_print_b("fork fail", info);
	else if (info->pid1 == 0)
	{
		input_stream(info);

	}

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:35:08 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/10 21:49:31 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc_info(t_info *info, char *av[], char *envp[])
{
	ft_memset(info, 0, sizeof(t_info));
	info->tag = ft_strjoin(av[2], "\n");
	if (info->tag == 0)
		err_print_hd("Memory allocation fail", info);
	info->outfile = av[5];
	info->outfile_fd = open(av[5], O_RDWR | O_CREAT | O_APPEND, 0644);
	info->envp = envp;
	info->path = path_list_b(info);
	if (ft_strncmp(av[3], "", ft_strlen(av[3])) != 0)
	{
		info->cmd1 = ft_split(av[3], ' ');
		if (info->cmd1 == 0)
			err_print_hd("Memory allocation fail", info);
		if (info->cmd1[0] != 0)
			info->cmd_path1 = merge_cmd_b(info->path, info->cmd1, info);
	}
	if (ft_strncmp(av[4], "", ft_strlen(av[4])) != 0)
	{
		info->cmd2 = ft_split(av[4], ' ');
		if (info->cmd2 == 0)
			err_print_hd("Memory allocation fail", info);
		if (info->cmd2[0] != 0)
			info->cmd_path2 = merge_cmd_b(info->path, info->cmd2, info);
	}
}

int	make_temp(t_info *info)
{
	int		fd;
	int		tries;
	char	*tmp;

	info->temp = ft_strdup("/tmp/mytempfile");
	if (info->temp == 0)
		err_print_hd("Memory allocation fail", info);
	tries = 10;
	while (tries > 0)
	{
		fd = open(info->temp, O_RDWR | O_CREAT, 0644);
		if (fd != -1)
			return (fd);
		tmp = info->temp;
		info->temp = ft_strjoin(tmp, "_123");
		free(tmp);
		if (info->temp == 0)
			err_print_hd("Memory allocation fail", info);
		tries--;
	}
	return (-1);
}

void	input_stream(t_info *info)
{
	char	*line;

	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(info->tag, line, ft_strlen(info->tag)))
		{
			free(line);
			break ;
		}
		write(info->temp_fd, line, ft_strlen(line));
		free(line);
	}
}

void	free_here_doc_utils(t_info *info)
{
	int	i;

	i = 0;
	if (info->path != 0)
	{
		while (info->path[i] != 0)
		{
			free(info->path[i]);
			i++;
		}
		free(info->path);
	}
	if (info->cmd_path1 != 0)
		free(info->cmd_path1);
	if (info->cmd_path2 != 0)
		free(info->cmd_path2);
	if (info->tag != 0)
		free(info->tag);
}

void	free_here_doc(t_info *info)
{
	int	i;

	i = 0;
	if (info->cmd1 != 0)
	{
		while (info->cmd1[i] != 0)
		{
			free(info->cmd1[i]);
			i++;
		}
		free(info->cmd1);
	}
	i = 0;
	if (info->cmd2 != 0)
	{
		while (info->cmd2[i] != 0)
		{
			free(info->cmd2[i]);
			i++;
		}
		free(info->cmd2);
	}
	free_here_doc_utils(info);
}

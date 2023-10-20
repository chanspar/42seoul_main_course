/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:09:00 by chanspar          #+#    #+#             */
/*   Updated: 2023/10/13 20:10:20 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_free(char **str)
{
	if (*str != 0)
	{
		free(*str);
		*str = 0;
	}
	return (0);
}

char	*make_line(long long idx, char *tmp)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (idx + 2));
	if (line == 0)
		return (0);
	line[idx + 1] = 0;
	while (idx >= 0)
	{
		line[idx] = tmp[idx];
		idx--;
	}
	return (line);
}

char	*make_line_rest(char **rest)
{
	long long	idx;
	char		*line;
	char		*tmp;

	idx = 0;
	while ((*rest)[idx] && (*rest)[idx] != '\n')
		idx++;
	if ((*rest)[idx] == 0)
	{
		line = ft_strdup(*rest);
		ft_free(rest);
		if (line == 0)
			return (0);
		return (line);
	}
	tmp = *rest;
	*rest = ft_strdup(tmp + idx + 1);
	if (rest == 0 || *rest == 0)
		return (ft_free(&tmp));
	line = make_line(idx, tmp);
	ft_free(&tmp);
	if (line == 0)
		ft_free(rest);
	return (line);
}

char	*read_file(char *buff, char **rest, int fd)
{
	ssize_t	rd_size;
	char	*tmp;

	while (!ft_strchr(*rest, '\n'))
	{
		rd_size = read(fd, buff, BUFFER_SIZE);
		if (rd_size == -1)
			return (ft_free(rest));
		else if (rd_size == 0)
			break ;
		buff[rd_size] = 0;
		tmp = *rest;
		*rest = ft_strjoin(tmp, buff);
		ft_free(&tmp);
		if (rest == 0 || *rest == 0)
			return (0);
	}
	return (make_line_rest(rest));
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (ft_free(&rest));
	if (rest == 0)
		rest = ft_strdup("");
	if (rest == 0)
		return (ft_free(&buff));
	line = read_file(buff, &rest, fd);
	ft_free(&buff);
	if (line == 0 || *line == 0)
		return (ft_free(&line));
	return (line);
}

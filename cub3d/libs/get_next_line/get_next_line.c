/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 05:18:10 by doukim            #+#    #+#             */
/*   Updated: 2023/04/30 21:56:58 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_cat_one_buffer(int fd, char **save)
{
	char	*buffer;
	int		readret;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	readret = read(fd, buffer, BUFFER_SIZE);
	if (readret < 1)
	{
		gnl_free_zero(&buffer);
		return (readret);
	}
	buffer[readret] = '\0';
	*save = gnl_strjoin(*save, buffer);
	return (readret);
}

char	*gnl_get_one_line(char **save)
{
	char	*line;
	char	*temp;
	char	*nl_loc;

	nl_loc = gnl_strchr(save, '\n');
	*nl_loc = '\0';
	line = gnl_strjoin(gnl_strdup(*save), gnl_strdup("\n"));
	*nl_loc = '\n';
	temp = *save;
	*save = gnl_strdup(nl_loc + 1);
	gnl_free_zero(&temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*save;
	char				*temp;
	int					gnl_cob_ret;

	while (gnl_strchr(&save, '\n') == NULL)
	{
		gnl_cob_ret = gnl_cat_one_buffer(fd, &save);
		if (gnl_cob_ret == 0)
		{
			if (gnl_strlen(save) == 0)
				gnl_free_zero(&save);
			temp = gnl_strdup(save);
			gnl_free_zero(&save);
			return (temp);
		}
		if (gnl_cob_ret == -1)
		{
			gnl_free_zero(&save);
			return (NULL);
		}
	}
	return (gnl_get_one_line(&save));
}

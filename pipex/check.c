/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:27:34 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/16 01:08:54 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_slash(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*merge_cmd(char **env_path, char **cmd)
{
	int		i;
	char	*cmd_tmp;
	char	*tmp;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (cmd[0]);
	cmd_tmp = ft_strjoin("/", cmd[0]);
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], cmd_tmp);
		if (access(tmp, X_OK) == 0)
		{
			free(cmd_tmp);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	free(cmd_tmp);
	return (0);
}

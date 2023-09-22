/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:13:29 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 16:25:51 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_slash_b(char **cmd)
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

char	*merge_utils_b(char **env_path, char *cmd_tmp, t_info *info)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env_path[i])
	{
		tmp = ft_strjoin(env_path[i], cmd_tmp);
		if (tmp == 0 || access(tmp, X_OK) == 0)
			free(cmd_tmp);
		if (tmp == 0)
			err_print_b("Memory allocation fail", info);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	free(cmd_tmp);
	return (0);
}

char	*merge_cmd_b(char **env_path, char **cmd, t_info *info)
{
	char	*cmd_tmp;
	char	*stay;

	if (access(cmd[0], X_OK) == 0)
	{
		stay = ft_strdup(cmd[0]);
		if (stay == 0)
			err_print_b("Memory allocation fail", info);
		return (stay);
	}
	cmd_tmp = ft_strjoin("/", cmd[0]);
	if (cmd_tmp == 0)
		err_print_b("Memory allocation fail", info);
	return (merge_utils_b(env_path, cmd_tmp, info));
}

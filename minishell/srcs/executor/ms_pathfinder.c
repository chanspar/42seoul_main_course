/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:41:36 by doukim            #+#    #+#             */
/*   Updated: 2024/01/26 20:09:24 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

char	**ms_get_envpath(char **envp)
{
	while (*envp)
	{
		if (!ms_strncmp(*envp, "PATH=", 5))
			return (ms_pathsplit(*envp + 5, ':'));
		envp++;
	}
	return (NULL);
}

int	ms_iscommand(char *filename)
{
	int	idx;

	idx = 0;
	while (filename[idx])
	{
		if (filename[idx] == '/')
			return (0);
		idx++;
	}
	return (1);
}

int	ms_chk_is_dir(char *filename)
{
	struct stat	filestat;

	lstat(filename, &filestat);
	errno = 0;
	if (S_ISDIR(filestat.st_mode))
	{
		ms_exeerror(filename, 3);
		exit(126);
	}
	return (1);
}

void	ms_get_cmdpath_permissiondenied_util(char *filename)
{
	if (!ms_strncmp(filename, "", 1))
	{
		ms_exeerror(filename, 2);
		exit(126);
	}
	else
	{
		ms_exeerror(filename, 4);
		exit(127);
	}
}

char	*ms_get_cmdpath(char *filename, char **envpath)
{
	int		is_command;
	char	*cmdpath;
	char	*cmdtmp;

	is_command = ms_iscommand(filename);
	cmdpath = ms_strjoin_f(ms_strdup("/"), ms_strdup(filename));
	while (is_command && envpath && *envpath && ms_strncmp(filename, "", 1))
	{
		cmdtmp = ms_strjoin_f(ms_strdup(*envpath), ms_strdup(cmdpath));
		if (!access(cmdtmp, X_OK))
		{
			free(cmdpath);
			return (cmdtmp);
		}
		envpath++;
		free(cmdtmp);
	}
	free(cmdpath);
	if (!is_command && !access(filename, X_OK) && ms_chk_is_dir(filename))
		return (ms_strdup(filename));
	if (errno == EACCES)
		ms_get_cmdpath_permissiondenied_util(filename);
	ms_exeerror(filename, is_command + 1);
	exit(127);
}

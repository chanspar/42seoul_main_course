/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:05 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/02 17:01:42 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_get_listsize(char **tk_list)
{
	int	tk_size;

	tk_size = 0;
	if (!tk_list)
		return (0);
	while (tk_list[tk_size])
		tk_size++;
	return (tk_size);
}

char	*ms_get_envname(char *envv)
{
	int		idx;
	char	*env_name;

	idx = 0;
	while (envv[idx] && envv[idx] != '=')
		idx++;
	env_name = ms_substr(envv, 0, idx);
	if (!env_name)
		malloc_err();
	return (env_name);
}

char	*ms_get_env_value(char *env_name, char **envp)
{
	int		i;
	int		j;
	char	*tmp_name;
	char	*env_value;

	i = 0;
	while (envp[i])
	{
		j = 0;
		tmp_name = ms_get_envname(envp[i]);
		if (!ms_strncmp(env_name, tmp_name, ms_strlen(env_name) + 1))
		{
			free(tmp_name);
			if (!ms_strchr(envp[i], '='))
				return (NULL);
			while (envp[i][j] && envp[i][j] != '=')
				j++;
			env_value = ms_substr(envp[i], j + 1, ms_strlen(envp[i]) - (j + 1));
			if (!env_value)
				malloc_err();
			return (env_value);
		}
		free(tmp_name);
		i++;
	}
	return (NULL);
}


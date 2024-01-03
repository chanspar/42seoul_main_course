/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:36 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 00:20:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_export_buitin(t_minishell *info, char **tk_list)
{
	if (tk_list[1] == 0)
		ms_only_cmd_export();
	else
		ms_check_export();



}

void	ms_only_cmd_export(char **envp)
{
	int	env_len;
	int	i;
	char	*env_name;
	char	*env_value;

	i = 0;
	env_len = ms_get_listsize(envp);
	sort_evnp(envp, env_len);
	while (i < env_len)
	{
		env_name = ms_get_envname(envp[i]);
		env_value = ms_get_env_value(env_name, envp);
		write(1, "declare -x ", 11);
		write(1, env_name, ft_strlen(env_name));
		if (ms_strchr(envp[i], '='))
		{
			write(1, "=\"", 2);
			write(1, env_value, ms_strlen(env_value));
			write(1,"\"", 1);
		}
		write(1, "\n", 1);
		free(env_name);
		free(env_value);
		i++;
	}
}

void	swap_string(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	sort_evnp(char **envp, int len)
{
	int	i;
	int	n;

	while (len--)
	{
		i = 0;
		while (envp[i] && envp[i + 1])
		{
			if (ms_strlen(envp[i]) < ms_strlen(envp[i + 1]))
				n = ms_strlen(envp[i]);
			else
				n = ms_strlen(envp[i + 1]);
			if (ms_strncmp(envp[i], envp[i + 1], n + 1) > 0)
				swap_string(&envp[i], &envp[i + 1]);
			i++;
		}
	}
}

void	ms_check_export(char **envp, char **tk_list)
{
	int	i;
	int flag;

	i = 0;
	while (tk_list[i])
	{
		flag = ms_check_key(tk_list[i]);
		if (flag == 1)
		{
			err();
		}
		else
			ms_add_export();

	}

}

int	ms_check_key(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '_' && !ms_isalpha(str[0]))
		return (1);
	while (str[i] && str[i] != '=')
	{
		if (!ms_isalpha(str[i]) && !ms_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);

}

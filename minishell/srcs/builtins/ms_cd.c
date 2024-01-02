/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:19:42 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/02 17:47:02 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_cd(t_minishell *info, char **tk_list)
{
	char	buffer[PATH_MAX];

	getcwd(buffer, PATH_MAX); //절대경로 버퍼에 복사
	ms_change_oldpwd(); // oldpwd에 저장
	if (tk_list[1] == 0)
		ms_cd_no_option(info);  //cd만 들어올 경우 홈으로 이동 하지말까
	else
		ms_cd_option(); //1.인자가 2개 들어온 경우 앞에꺼만 판단  2.-a 이런거 들어오면 그냥 안된다고 끝내기 -인 디렉토리  3.-,~ 이런거 구현안해도됨
	//.. .이거 자동으로 됨 
	//지금 경로의 디렉토리를 삭제하면 cd .   
//cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory
}

int	ms_cd_no_option(t_minishell *info)
{
	char	*path;

	path = ms_get_home(info);
	if (chdir(path) == -1)
	{
		errono("home x");
		return (BUILT_FAIL);
	}
}

int	ms_cd_option(char *path)
{
	
}


char	*ms_get_home(t_minishell *info)
{
	int		i;
	char	*home_path;

	i = 0;
	while (info->envp[i])
	{
		if (ms_strncmp("HOME=", info->envp[i], 5) == 0)
		{
			home_path = ms_strdup(info->envp[i] + 5);
			if (home_path == 0)
				malloc_err();
			return (home_path);
		}
		i++;
	}
	return (0);
}


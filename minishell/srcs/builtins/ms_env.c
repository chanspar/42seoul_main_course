/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:21:17 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 00:21:22 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_env_buitin(t_minishell *info, )
{
	int	i;

	i = 0;
	while (info->envp[i])
	{
		write(1, info->envp[i], ms_strlen(info->envp[i]));
		write(1, "\n", 1);
		i++;
	}
	return (BUILT_SUCESS);
}

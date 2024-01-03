/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:49 by doukim            #+#    #+#             */
/*   Updated: 2024/01/02 17:29:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "ms_minishell.h"
# include "limits.h"


# define BUILT_SUCESS 0
# define BUILT_FAIL 1
# define NO_BUILT 2

int		ms_check_builtin(t_minishell *info, char **tk_list);
int		ms_check_echo_option(char *str);
void	ms_echo_no_option(char **tk_list);
void	ms_echo_option(char **tk_list, int idx);
int		ms_echo_print(char **tk_list);


int		ms_pwd(void);


int		ms_get_listsize(char **tk_list);
char	*ms_get_envname(char *envv);
char	*ms_get_env_value(char *env_name, char **envp);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:22:31 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 10:57:55 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	ms_get_type(char *str)
{
	if (str == NULL)
		return (T_NULL);
	else if (!ms_strncmp(str, "|", 2))
		return (T_PIPE);
	else if (!ms_strncmp(str, "<", 2))
		return (T_L);
	else if (!ms_strncmp(str, ">", 2))
		return (T_R);
	else if (!ms_strncmp(str, "<<", 3))
		return (T_LL);
	else if (!ms_strncmp(str, ">>", 3))
		return (T_RR);
	else
		return (T_WORD);
}

static t_token	*ms_get_token(char *str)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));
	if (!ret)
		return (NULL);
	ret->type = ms_get_type(str);
	if (str && (str[0] == '\"' || str[0] == '\''))
		str++;
	ret->str = ms_strdup(str);
	return (ret);
}

t_list	*ms_tokenize(t_list *splited)
{
	t_list	*ret;
	t_list	*tmp;
	t_token	*tokentmp;

	ret = NULL;
	tmp = splited;
	while (tmp)
	{
		tokentmp = ms_get_token(tmp->data);
		if (!tokentmp)
			return (NULL);
		ms_lstadd(&ret, tokentmp);
		tmp = tmp->next;
	}
	tokentmp = ms_get_token(NULL);
	if (!tokentmp)
		return (NULL);
	ms_lstadd(&ret, tokentmp);
	return (ret);
}

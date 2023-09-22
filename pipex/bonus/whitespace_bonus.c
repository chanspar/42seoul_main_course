/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitespace_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:07:49 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 22:08:06 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	word_cnt1(char *str, char c)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 1;
	while (*str)
	{
		if (*str == c || (*str >= 8 && *str <= 13))
			flag = 1;
		else if ((*str != c && (*str < 8 || *str > 13)) && flag == 1)
		{	
			cnt++;
			flag = 0;
		}
		str++;
	}
	return (cnt);
}

int	mal_str1(char **p, char *str, char c)
{
	int		cnt;
	int		i;
	int		wd_cnt;
	char	*tmp;

	i = 0;
	wd_cnt = word_cnt1(str, c);
	while (i < wd_cnt)
	{
		while ((*str == c || (*str >= 8 && *str <= 13)) && *str != 0)
			str++;
		cnt = 0;
		tmp = str;
		while ((*str != c && (*str < 8 || *str > 13)) && *str != 0)
		{
			str++;
			cnt++;
		}
		*(p + i) = (char *)malloc(sizeof(char) * (cnt + 1));
		if (*(p + i) == 0)
			return (fail_free(p, i));
		ft_strlcpy(*(p + i), tmp, cnt + 1);
		i++;
	}
	return (1);
}

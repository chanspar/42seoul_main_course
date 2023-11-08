/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:50:25 by chanspar          #+#    #+#             */
/*   Updated: 2023/11/08 21:01:50 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lower_case(char *color, int idx, int *num)
{
	char	*tmp1;
	int		i;

	tmp1 = "0123456789abcdef";
	i = 0;
	while (tmp1[i])
	{
		if (tmp1[i] == color[idx])
			*num += i;
		i++;
	}
}

void	upper_case(char *color, int idx, int *num)
{
	char	*tmp2;
	int		i;

	tmp2 = "0123456789ABCDEF";
	i = 0;
	while (tmp2[i])
	{
		if (tmp2[i] == color[idx])
			*num += i;
		i++;
	}
}

int	make_rgb(char *color)
{
	int		idx;
	int		num;

	if (ft_strncmp(color, "0x", 2) != 0)
		return (0xffffff);
	idx = 2;
	num = 0;
	while (color[idx])
	{
		num *= 16;
		if ('a' <= color[idx] && color[idx] <= 'f')
			lower_case(color, idx, &num);
		else
			upper_case(color, idx, &num);
		idx++;
	}
	return (num);
}

void	get_color(t_info *info, char *str, int i, int j)
{
	int		k;
	int		idx;
	int		flag;

	k = 0;
	flag = 0;
	while (str[k])
	{
		if (str[k] == ',')
		{
			idx = k + 1;
			flag = 1;
		}
		k++;
	}
	if (flag == 0)
		info->color[j][i] = 0xffffff;
	else
		info->color[j][i] = make_rgb(str + idx);
}

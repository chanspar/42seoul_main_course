/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:53:36 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/04 15:40:07 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_err1(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_digit1(char **tmp)
{
	int	i;

	i = 0;
	while ((*tmp)[i])
	{
		if ((*tmp)[i] == '-' || (*tmp)[i] == '+')
			i++;
		if ((*tmp)[i] > '9' || (*tmp)[i] < '0')
			print_err1();
		i++;
	}
	if (ft_strlen(*tmp) > 11)
		print_err1();
}

void	check_same1(t_info *info)
{
	t_d_list	*cur1;
	t_d_list	*cur2;
	int			num_tmp;

	cur1 = info->head_a->rlink;
	while (cur1 != info->tail_a)
	{
		num_tmp = cur1->data;
		cur2 = cur1->rlink;
		while (cur2 != info->tail_a)
		{
			if (num_tmp == cur2->data)
				print_err1();
			cur2 = cur2->rlink;
		}
		cur1 = cur1->rlink;
	}
}

void	check_error_push1(char *argv[], t_info *info)
{
	char	**p;
	char	**tmp;
	long	num;

	while (*(++argv))
	{
		p = ft_split(*argv, ' ');
		tmp = p;
		if (*tmp == 0)
			print_err1();
		while (*tmp)
		{
			check_digit1(tmp);
			num = ft_atoi(*tmp);
			if (num > 2147483647 || num < -2147483648)
				print_err1();
			push_back(num, info->tail_a);
			free(*tmp);
			tmp++;
		}
		free(p);
	}
	check_same1(info);
	info->size_a = list_size(info->head_a, info->tail_a);
}

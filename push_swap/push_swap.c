/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:15:59 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/05 18:04:52 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arr(t_info *info)
{
	t_d_list	*head;
	t_d_list	*next;

	head = info->head_a->rlink;
	next = info->head_a->rlink->rlink;
	while (next != info->tail_a)
	{
		if (head->data > next->data)
			return (0);
		head = head->rlink;
		next = next->rlink;
	}
	return (1);
}

int	find_min(t_info *info)
{
	t_d_list	*head;
	int			pos;
	int			pos_save;

	head = info->head_a->rlink;
	info->min = head->data;
	pos = 0;
	pos_save = 0;
	while (head != info->tail_a->llink)
	{
		pos++;
		head = head->rlink;
		if (info->min > head->data)
		{
			info->min = head->data;
			pos_save = pos;
		}
	}
	return (pos_save);
}

void	a_sort(t_info *info, int pos)
{
	int	a;

	if ((info->size_a / 2) >= pos)
	{
		while (pos--)
			rotate_a(info, 1);
	}
	else
	{
		a = info->size_a - pos;
		while (a--)
			reverse_rotate_a(info, 1);
	}
}

int	main(int argc, char *argv[])
{
	t_info	*info;
	int		pos;

	if (argc <= 1)
		return (0);
	info = (t_info *)malloc(sizeof(t_info));
	if (info == 0)
		return (0);
	init_list(info);
	check_error_push(argv, info);
	if (check_arr(info) == 1)
		exit (0);
	division(info);
	greedy(info);
	pos = find_min(info);
	a_sort(info, pos);
	free_list(info);
	free(info);
	return (0);
}

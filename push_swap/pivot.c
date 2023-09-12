/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:00:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/05 18:14:42 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_big(t_info *info, int cnt)
{
	int			pos;

	pos = find_min(info);
	if (cnt == info->size_a)
	{
		info->ra = pos;
		info->rra = ((info->size_a) - pos);
	}
	else
	{
		info->ra = cnt;
		info->rra = ((info->size_a) - cnt);
	}
}

void	all_small(t_info *info, int cnt)
{
	int			pos;

	pos = find_min(info);
	if (cnt == info->size_a)
	{
		info->ra = pos;
		info->rra = ((info->size_a) - pos);
	}
	else
	{
		info->rra = cnt;
		info->ra = ((info->size_a) - cnt);
	}
}

void	find_pivot(t_info *info)
{
	t_d_list	*head;
	int			sum;

	sum = 0;
	head = info->head_a->rlink;
	while (head != info->tail_a)
	{
		sum += head->data;
		head = head->rlink;
	}
	sum = sum / info->size_a;
	info->pivot1 = sum + (info->size_a / 6);
	info->pivot2 = sum - (info->size_a / 6);
}

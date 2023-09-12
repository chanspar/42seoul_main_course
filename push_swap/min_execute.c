/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:39:23 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:03:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_data(t_info *info, int pos)
{
	t_d_list	*head;

	head = info->head_b->rlink;
	while (pos)
	{
		head = head->rlink;
		pos--;
	}
	return (head->data);
}

void	min_insert_utils(t_info *info, int data, t_d_list *head)
{
	int			cnt;
	t_d_list	*tail;

	cnt = 0;
	tail = info->tail_a->llink;
	if (head->data < data)
	{
		while (head->data < data && head != info->tail_a)
		{
			cnt++;
			head = head->rlink;
		}
		all_big(info, cnt);
	}
	else
	{
		while (tail->data > data && tail != info->head_a)
		{
			cnt++;
			tail = tail->llink;
		}
		all_small(info, cnt);
	}
}

void	min_insert(t_info *info, int pos)
{
	t_d_list	*head;
	int			data;

	head = info->head_a->rlink;
	data = pos_data(info, pos);
	info->rb = pos;
	info->rrb = (info->size_b - pos);
	min_insert_utils(info, data, head);
}

int	combi_rotate(t_info *info)
{
	int	min;
	int	rb_ra;
	int	rb_rra;
	int	rrb_ra;
	int	rrb_rra;

	rb_rra = info->rb + info->rra;
	rrb_ra = info->rrb + info->ra;
	if (info->rb > info->ra)
		rb_ra = info->rb;
	else
		rb_ra = info->ra;
	if (info->rrb > info->rra)
		rrb_rra = info->rrb;
	else
		rrb_rra = info->rra;
	min = rb_rra;
	if (min > rrb_ra)
		min = rrb_ra;
	if (min > rb_ra)
		min = rb_ra;
	if (min > rrb_rra)
		min = rrb_rra;
	return (min);
}

int	min_cnt(t_info *info)
{
	int	pos;
	int	tmp;
	int	min;
	int	pos_save;

	pos = 0;
	min = 2147483647;
	while (pos < info->size_b)
	{
		min_insert(info, pos);
		tmp = combi_rotate(info);
		if (min > tmp)
		{
			min = tmp;
			pos_save = pos;
		}
		pos++;
	}
	return (pos_save);
}

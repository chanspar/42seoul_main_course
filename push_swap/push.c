/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:08:18 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:00:32 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_info *info, int i)
{
	t_d_list	*tmp;

	if (info->size_b < 1)
		return ;
	tmp = info->head_b->rlink;
	info->head_b->rlink = info->head_b->rlink->rlink;
	info->head_b->rlink->llink = info->head_b;
	info->head_a->rlink->llink = tmp;
	tmp->rlink = info->head_a->rlink;
	info->head_a->rlink = tmp;
	tmp->llink = info->head_a;
	(info->size_a)++;
	(info->size_b)--;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	push_b(t_info *info, int i)
{
	t_d_list	*tmp;

	if (info->size_a < 1)
		return ;
	tmp = info->head_a->rlink;
	info->head_a->rlink = info->head_a->rlink->rlink;
	info->head_a->rlink->llink = info->head_a;
	info->head_b->rlink->llink = tmp;
	tmp->rlink = info->head_b->rlink;
	info->head_b->rlink = tmp;
	tmp->llink = info->head_b;
	(info->size_a)--;
	(info->size_b)++;
	if (i == 1)
		write(1, "pb\n", 3);
}

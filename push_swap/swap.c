/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:11:47 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:00:34 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_info *info, int i)
{
	int	data_tmp;

	if (info->size_a < 2)
		return ;
	data_tmp = info->head_a->rlink->data;
	info->head_a->rlink->data = info->head_a->rlink->rlink->data;
	info->head_a->rlink->rlink->data = data_tmp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_info *info, int i)
{
	int	data_tmp;

	if (info->size_b < 2)
		return ;
	data_tmp = info->head_b->rlink->data;
	info->head_b->rlink->data = info->head_b->rlink->rlink->data;
	info->head_b->rlink->rlink->data = data_tmp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_info *info, int i)
{
	int	data_tmp;

	if (info->size_a < 2)
		return ;
	if (info->size_b < 2)
		return ;
	data_tmp = info->head_a->rlink->data;
	info->head_a->rlink->data = info->head_a->rlink->rlink->data;
	info->head_a->rlink->rlink->data = data_tmp;
	data_tmp = info->head_b->rlink->data;
	info->head_b->rlink->data = info->head_b->rlink->rlink->data;
	info->head_b->rlink->rlink->data = data_tmp;
	if (i == 1)
		write(1, "ss\n", 3);
}

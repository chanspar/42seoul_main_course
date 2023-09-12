/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:56:04 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:00:24 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_info *info, int i)
{
	int	data;

	if (info->size_a < 2)
		return ;
	data = pop_back(info->tail_a);
	push_front(data, info->head_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_info *info, int i)
{
	int	data;

	if (info->size_b < 2)
		return ;
	data = pop_back(info->tail_b);
	push_front(data, info->head_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_info *info, int i)
{
	int	data;

	if (info->size_a < 2)
		return ;
	if (info->size_b < 2)
		return ;
	data = pop_back(info->tail_a);
	push_front(data, info->head_a);
	data = pop_back(info->tail_b);
	push_front(data, info->head_b);
	if (i == 1)
		write(1, "rrr\n", 4);
}

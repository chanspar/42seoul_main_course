/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:11:27 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 16:59:10 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_info *info, int i)
{
	int	data;

	if (info->size_a < 2)
		return ;
	data = pop_front(info->head_a);
	push_back(data, info->tail_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_info *info, int i)
{
	int	data;

	if (info->size_b < 2)
		return ;
	data = pop_front(info->head_b);
	push_back(data, info->tail_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_info *info, int i)
{
	int	data;

	if (info->size_a < 2)
		return ;
	if (info->size_b < 2)
		return ;
	data = pop_front(info->head_a);
	push_back(data, info->tail_a);
	data = pop_front(info->head_b);
	push_back(data, info->tail_b);
	if (i == 1)
		write(1, "rr\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:26:32 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/05 18:15:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_case(t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->head_a->rlink->data;
	second = info->head_a->rlink->rlink->data;
	third = info->head_a->rlink->rlink->rlink->data;
	if (first > second && first < third)
		swap_a(info, 1);
	else if (first > second && second > third)
	{
		swap_a(info, 1);
		reverse_rotate_a(info, 1);
	}
	else if (first > third && second < third)
		rotate_a(info, 1);
	else if (first < third && second > third)
	{
		swap_a(info, 1);
		rotate_a(info, 1);
	}
	else if (first < second && first > third)
		reverse_rotate_a(info, 1);
}

void	two_case(t_info *info)
{
	int	first;
	int	second;

	first = info->head_a->rlink->data;
	second = info->head_a->rlink->rlink->data;
	if (first > second)
		swap_a(info, 1);
}

void	three_div(t_info *info)
{
	int	i;

	find_pivot(info);
	i = info->size_a;
	while (i && info->size_a > 3)
	{
		if (info->pivot1 <= info->head_a->rlink->data)
			rotate_a(info, 1);
		else
		{
			push_b(info, 1);
			if (info->pivot2 > info->head_b->rlink->data)
				rotate_b(info, 1);
		}
		i--;
	}
}

void	division(t_info *info)
{	
	if (info->size_a > 200)
		three_div(info);
	while (info->size_a > 3)
		push_b(info, 1);
	if (info->size_a == 3)
		three_case(info);
	else if (info->size_a == 2)
		two_case(info);
}

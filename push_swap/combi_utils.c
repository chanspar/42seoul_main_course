/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combi_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:42:10 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:03:29 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_ra_case(t_info *info)
{
	int	gap;
	int	a;

	if (info->rb >= info->ra)
	{
		a = info->ra;
		gap = info->rb - info->ra;
		while (a--)
			rr(info, 1);
		while (gap--)
			rotate_b(info, 1);
	}
	else
	{
		a = info->rb;
		gap = info->ra - info->rb;
		while (a--)
			rr(info, 1);
		while (gap--)
			rotate_a(info, 1);
	}
}

void	rrb_rra_case(t_info *info)
{
	int	gap;
	int	a;

	if (info->rrb >= info->rra)
	{
		gap = info->rrb - info->rra;
		a = info->rra;
		while (a--)
			rrr(info, 1);
		while (gap--)
			reverse_rotate_b(info, 1);
	}
	else
	{
		a = info->rrb;
		gap = info->rra - info->rrb;
		while (a--)
			rrr(info, 1);
		while (gap--)
			reverse_rotate_a(info, 1);
	}
}

void	rb_rra_case(t_info *info)
{
	int	a;
	int	b;

	a = info->rb;
	b = info->rra;
	while (a--)
		rotate_b(info, 1);
	while (b--)
		reverse_rotate_a(info, 1);
}

void	rrb_ra_case(t_info *info)
{
	int	a;
	int	b;

	a = info->rrb;
	b = info->ra;
	while (a--)
		reverse_rotate_b(info, 1);
	while (b--)
		rotate_a(info, 1);
}

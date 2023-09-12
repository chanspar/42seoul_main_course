/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:58:44 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/04 20:49:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_util(t_info *info, int rb_ra, int rrb_rra)
{
	int	rb_rra;
	int	rrb_ra;

	rb_rra = info->rb + info->rra;
	rrb_ra = info->rrb + info->ra;
	if (rb_ra <= rb_rra && rb_ra <= rrb_ra && rb_ra <= rrb_rra)
		rb_ra_case(info);
	else if (rb_rra <= rb_ra && rb_rra <= rrb_ra && rb_rra <= rrb_rra)
		rb_rra_case(info);
	else if (rrb_ra <= rb_ra && rrb_ra <= rb_rra && rrb_ra <= rrb_rra)
		rrb_ra_case(info);
	else if (rrb_rra <= rb_ra && rrb_rra <= rb_rra && rrb_rra <= rrb_ra)
		rrb_rra_case(info);
}

void	min_exe(t_info *info)
{
	int	rb_ra;
	int	rrb_rra;

	if (info->rb > info->ra)
		rb_ra = info->rb;
	else
		rb_ra = info->ra;
	if (info->rrb > info->rra)
		rrb_rra = info->rrb;
	else
		rrb_rra = info->rra;
	exe_util(info, rb_ra, rrb_rra);
}

void	greedy(t_info *info)
{
	int	pos_save;

	if (info->size_b == 0)
		return ;
	pos_save = min_cnt(info);
	min_insert(info, pos_save);
	min_exe(info);
	push_a(info, 1);
	greedy(info);
}

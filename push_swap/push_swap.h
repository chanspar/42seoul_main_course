/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:16:40 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/05 17:57:17 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_double_list
{
	int						data;
	struct s_double_list	*llink;
	struct s_double_list	*rlink;
}	t_d_list;

typedef struct s_info
{
	int			size_a;
	t_d_list	*head_a;
	t_d_list	*tail_a;
	int			size_b;
	t_d_list	*head_b;
	t_d_list	*tail_b;
	int			rb;
	int			rrb;
	int			ra;
	int			rra;
	int			pivot1;
	int			pivot2;
	int			min;
}	t_info;

void			print_err(void);
void			check_digit(char **tmp);
void			check_error_push(char *argv[], t_info *info);
void			init_list(t_info *info);
t_d_list		*makenode(int value);
void			push_back(int value, t_d_list *tail);
void			push_front(int value, t_d_list *head);
int				pop_back(t_d_list *tail);
int				pop_front(t_d_list *head);
int				list_size(t_d_list *head, t_d_list *tail);
void			free_list(t_info *info);
void			swap_a(t_info *info, int i);
void			swap_b(t_info *info, int i);
void			ss(t_info *info, int i);
void			push_a(t_info *info, int i);
void			push_b(t_info *info, int i);
void			rotate_a(t_info *info, int i);
void			rotate_b(t_info *info, int i);
void			rr(t_info *info, int i);
void			reverse_rotate_a(t_info *info, int i);
void			reverse_rotate_b(t_info *info, int i);
void			rrr(t_info *info, int i);

void			three_case(t_info *info);
void			two_case(t_info *info);
void			division(t_info *info);
void			three_div(t_info *info);
void			find_pivot(t_info *info);

int				pos_data(t_info *info, int pos);
void			min_insert(t_info *info, int pos);
void			min_insert_utils(t_info *info, int data, t_d_list *head);
int				combi_rotate(t_info *info);
int				min_cnt(t_info *info);

void			rb_ra_case(t_info *info);
void			rrb_rra_case(t_info *info);
void			rb_rra_case(t_info *info);
void			rrb_ra_case(t_info *info);
void			exe_util(t_info *info, int rb_ra, int rrb_rra);
void			min_exe(t_info *info);
void			greedy(t_info *info);

int				check_arr(t_info *info);
int				find_min(t_info *info);
void			a_sort(t_info *info, int pos);

void			all_big(t_info *info, int cnt);
void			all_small(t_info *info, int cnt);

#endif
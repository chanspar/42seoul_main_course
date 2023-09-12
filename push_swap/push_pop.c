/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:07:50 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/04 17:35:40 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(int value, t_d_list *tail)
{
	t_d_list	*new_node;
	t_d_list	*last;

	last = tail->llink;
	new_node = makenode(value);
	last->rlink = new_node;
	new_node->llink = last;
	tail->llink = new_node;
	new_node->rlink = tail;
}

void	push_front(int value, t_d_list *head)
{
	t_d_list	*new_node;
	t_d_list	*first;

	first = head->rlink;
	new_node = makenode(value);
	first->llink = new_node;
	new_node->rlink = first;
	new_node->llink = head;
	head->rlink = new_node;
}

int	pop_front(t_d_list *head)
{
	t_d_list	*first;
	t_d_list	*second;
	int			data;

	first = head->rlink;
	second = head->rlink->rlink;
	head->rlink = second;
	second->llink = head;
	first->rlink = NULL;
	first->llink = NULL;
	data = first->data;
	free(first);
	return (data);
}

int	pop_back(t_d_list *tail)
{
	t_d_list	*b_first;
	t_d_list	*b_second;
	int			data;

	b_first = tail->llink;
	b_second = tail->llink->llink;
	tail->llink = b_second;
	b_second->rlink = tail;
	b_first->rlink = NULL;
	b_first->llink = NULL;
	data = b_first->data;
	free(b_first);
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:22:28 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/04 17:35:34 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_info *info)
{
	info->head_a = (t_d_list *)malloc(sizeof(t_d_list));
	info->tail_a = (t_d_list *)malloc(sizeof(t_d_list));
	info->head_b = (t_d_list *)malloc(sizeof(t_d_list));
	info->tail_b = (t_d_list *)malloc(sizeof(t_d_list));
	if (info->head_a == NULL)
		exit(1);
	if (info->tail_a == NULL)
		exit(1);
	if (info->head_b == NULL)
		exit(1);
	if (info->tail_a == NULL)
		exit(1);
	info->head_a->data = 0;
	info->tail_a->data = 0;
	info->head_b->data = 0;
	info->tail_b->data = 0;
	info->head_a->rlink = info->tail_a;
	info->head_a->llink = info->head_a;
	info->tail_a->rlink = info->tail_a;
	info->tail_a->llink = info->head_a;
	info->head_b->rlink = info->tail_b;
	info->head_b->llink = info->head_b;
	info->tail_b->rlink = info->tail_b;
	info->tail_b->llink = info->head_b;
	info->size_b = 0;
}

t_d_list	*makenode(int value)
{
	t_d_list	*node;

	node = (t_d_list *)malloc(sizeof(t_d_list));
	if (node == NULL)
		exit(1);
	node->llink = NULL;
	node->rlink = NULL;
	node->data = value;
	return (node);
}

int	list_size(t_d_list *head, t_d_list *tail)
{
	t_d_list	*p;
	int			size;

	size = 0;
	p = head->rlink;
	while (p != tail)
	{
		p = p->rlink;
		size++;
	}
	return (size);
}

void	free_list(t_info *info)
{
	t_d_list	*tmp;

	while (info->head_a != info->tail_a)
	{
		tmp = info->head_a;
		info->head_a = info->head_a->rlink;
		free(tmp);
	}
	free(info->tail_a);
	while (info->head_b != info->tail_b)
	{
		tmp = info->head_b;
		info->head_b = info->head_b->rlink;
		free(tmp);
	}
	free(info->tail_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:29:24 by chanspar          #+#    #+#             */
/*   Updated: 2023/04/06 16:26:00 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = ft_lstlast(*lst);
	if (lst == 0 || new == 0)
		return ;
	if (last_list == 0)
		*lst = new;
	else
		last_list->next = new;
}

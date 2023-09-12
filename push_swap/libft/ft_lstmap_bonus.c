/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:47:21 by chanspar          #+#    #+#             */
/*   Updated: 2023/04/07 19:14:55 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*p_link;
	void	*lst_content;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	p = 0;
	while (lst != 0)
	{
		lst_content = f(lst->content);
		p_link = ft_lstnew(lst_content);
		if (p_link == 0)
		{
			del(lst_content);
			ft_lstclear(&p, del);
			return (0);
		}
		ft_lstadd_back(&p, p_link);
		lst = lst->next;
	}
	return (p);
}

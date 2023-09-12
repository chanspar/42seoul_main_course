/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:36:41 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/05 18:18:01 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_right_command(t_info *info, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		swap_a(info, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		swap_b(info, 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ss(info, 0);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		push_a(info, 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		push_b(info, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		rotate_a(info, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		rotate_b(info, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		rr(info, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		reverse_rotate_a(info, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		reverse_rotate_b(info, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		rrr(info, 0);
	else
		print_err1();
}

void	input_command(t_info *info)
{
	char	*line;
	char	*tmp;

	line = get_next_line(0);
	while (line && *line)
	{
		tmp = line;
		check_right_command(info, line);
		free(tmp);
		line = get_next_line(0);
	}
}

int	check_arr1(t_info *info)
{
	t_d_list	*head;
	t_d_list	*next;

	head = info->head_a->rlink;
	next = info->head_a->rlink->rlink;
	while (next != info->tail_a)
	{
		if (head->data > next->data)
			return (0);
		head = head->rlink;
		next = next->rlink;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac <= 1)
		return (0);
	info = (t_info *)malloc(sizeof(t_info));
	if (info == 0)
		return (0);
	init_list(info);
	check_error_push1(av, info);
	input_command(info);
	if (check_arr1(info) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(info);
	free(info);
	return (0);
}

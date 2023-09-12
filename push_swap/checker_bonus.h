/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:35:37 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/04 16:34:03 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line/get_next_line.h"

void	check_right_command(t_info *info, char *line);
int		check_arr1(t_info *info);
void	input_command(t_info *info);
void	check_error_push1(char *argv[], t_info *info);
void	check_same1(t_info *info);
void	check_digit1(char **tmp);
void	print_err1(void);
#endif
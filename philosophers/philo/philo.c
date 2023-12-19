/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:32:57 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/19 19:19:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char *av[])
{
	t_system	system;

	if (ac != 5 && ac != 6)
		return (err_print(E_ARGERR));
	if (arg_parse(&system, ac, av) == 1)
		return (1);
	//뮤텍스를 init 세팅 

	return (0);
}

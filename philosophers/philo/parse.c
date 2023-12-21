/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:16:29 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 20:08:51 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_parse(t_system *system, int ac, char *av[])
{
	memset(system, 0, sizeof(t_system));
	system->num_philo = ft_atoi(av[1]);
	system->time_to_die = ft_atoi(av[2]);
	system->time_to_eat = ft_atoi(av[3]);
	system->time_to_sleep = ft_atoi(av[4]);
	system->must_eat = -1;
	system->time = gettime();
	if (ac == 6)
		system->must_eat = ft_atoi(av[5]);
	if (check_arg(system, ac) == 1)
		return (1);
	if (pthread_mutex_init(&(system->message), NULL) != 0)
		return (err_print(E_MUTEXERR));
	if (pthread_mutex_init(&(system->lock), NULL) != 0)
		return (free_system(system, 1, E_MUTEXERR, 0));
	return (0);
}

int	check_arg(t_system *system, int ac)
{
	if (system->num_philo < 1)
		return (err_print(E_NUMPHILOERR));
	if (system->time_to_die < 1)
		return (err_print(E_TTDERR));
	if (system->time_to_eat < 1)
		return (err_print(E_TTEERR));
	if (system->time_to_sleep < 1)
		return (err_print(E_TTSERR));
	if (system->must_eat < 1 && ac == 6)
		return (err_print(E_MUSTEATERR));
	return (0);
}

long long	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

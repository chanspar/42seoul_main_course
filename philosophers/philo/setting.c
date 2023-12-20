/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:47:46 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/19 20:26:07 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_env(t_system *system)
{
	if (set_philos(system) == 1)
		return (1);
	if (set_fork(system) == 1)
		return (1);
	system->state = ACTIVE;
	return (0);
}

int	set_philos(t_system *system)
{
	int	i;

	i = 0;
	system->philos = (t_philo *)malloc(sizeof(t_philo) * system->num_philo);
	if (!system->philos)
		return (err_print(E_MALERR));
	while (i < system->num_philo)
	{
		system->philos[i].id = i + 1;
		system->philos[i].eat_cnt = 0;
		system->philos[i].life = gettime();
		system->philos[i].system = system;
		i++;
	}
	return (0);
}

int	set_fork(t_system *system)
{
	int	i;

	i = 0;
	system->forks = malloc(sizeof(pthread_mutex_t) * system->num_philo);
	if (!system->forks)
		return (err_print(E_MALERR));
	while (i < system->num_philo)
	{
		if (pthread_mutex_init(&(system->forks[i]), NULL) != 0)
			return (err_print(E_MUTEXERR));
		i++;
	}
	system->philos[0].l_fork = &system->forks[0];
	system->philos[0].r_fork = &system->forks[system->num_philo - 1];
	i = 1;
	while (i <system->num_philo)
	{
		system->philos[i].l_fork = &system->forks[i];
		system->philos[i].r_fork = &system->forks[i - 1];
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:08:45 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/23 15:43:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_case(t_system *system)
{
	int	i;

	if (system->num_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_onesleep(system->time_to_die);
		printf("%d 1 died\n", system->time_to_die);
	}
	else
	{
		system->time = gettime();
		if (system->time == -1)
			return (free_system(system, 4, e_gettimeerr, system->num_philo));
		if (thread_exe(system))
			return (free_system(system, 0, e_threaderr, system->num_philo));
		if (thread_exe2(system))
			return (free_system(system, 0, e_threaderr, system->num_philo));
		i = 0;
		while (i < system->num_philo)
			pthread_join(system->philos[i++].thread, NULL);
	}
	free_all(system);
	return (0);
}

int	thread_exe(t_system *system)
{
	int	i;

	i = 0;
	while (1)
	{
		if (pthread_create(&system->philos[i].thread, NULL, \
		thread_action, &system->philos[i]) != 0)
			return (1);
		i += 2;
		if (i >= system->num_philo)
			break ;
	}
	return (0);
}

int	thread_exe2(t_system *system)
{
	int	i;

	i = 1;
	while (1)
	{
		if (pthread_create(&system->philos[i].thread, NULL, \
		thread_action2, &system->philos[i]) != 0)
			return (1);
		i += 2;
		if (i >= system->num_philo)
			break ;
	}
	return (0);
}

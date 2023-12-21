/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:08:45 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 20:14:03 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_case(t_system *system)
{
	int	i;

	if (system->num_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(system->time_to_die, 0);
		printf("%d 1 died\n", system->time_to_die);
	}
	else
	{
		i = 0;
		if (thread_exe(system, i))
			return (free_system(system, 0, E_THREADERR, system->num_philo));
		ft_usleep(system->time_to_eat / 2, 0);
		i = 1;
		if (thread_exe(system, i))
			return (free_system(system, 0, E_THREADERR, system->num_philo));
		i = 0;
		while (i < system->num_philo)
			pthread_join(system->philos[i++].thread, NULL);
	}
	free_all(system);
	return (0);
}

int	thread_exe(t_system *system, int i)
{
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


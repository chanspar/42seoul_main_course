/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:09:23 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 20:08:48 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	system_state(t_system *system)
{
	int	state;

	pthread_mutex_lock(&system->lock);
	state = system->state;
	pthread_mutex_unlock(&system->lock);
	return (state);
}

int	philo_state(t_philo *philo)
{
	int	time;

	time = gettime() - philo->last_eat;
	if (time > philo->system->time_to_die)
	{
		message("died", philo);
		return (1);
	}
	return (0);
}

int	check_state(t_philo *philo)
{
	if (system_state(philo->system) || philo_state(philo))
		return (1);
	return (0);
}

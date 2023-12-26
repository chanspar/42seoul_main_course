/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:06:06 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/23 12:47:07 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_system(t_system *system, int flag, t_err err, int idx)
{
	int	i;

	pthread_mutex_destroy(&system->message);
	if (flag == 1)
		return (err_print(err));
	pthread_mutex_destroy(&system->lock);
	if (flag == 2)
		return (err_print(err));
	if (system->philos)
		free(system->philos);
	if (flag == 3)
		return (err_print(err));
	if (system->forks)
		free(system->forks);
	i = 0;
	while (i < idx)
	{
		pthread_mutex_destroy(&system->forks[i]);
		i++;
	}
	if (flag == 4)
		return (err_print(err));
	return (err_print(e_threaderr));
}

void	free_all(t_system *system)
{
	int	i;

	pthread_mutex_destroy(&system->message);
	pthread_mutex_destroy(&system->lock);
	if (system->philos)
		free(system->philos);
	if (system->forks)
		free(system->forks);
	i = 0;
	while (i < system->num_philo)
	{
		pthread_mutex_destroy(&system->forks[i]);
		i++;
	}
}

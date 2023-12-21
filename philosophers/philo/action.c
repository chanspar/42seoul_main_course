/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:10:51 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 20:08:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_action(void *ptr)
{
	t_philo	*philo;
	int		must_eat_num;

	philo = (t_philo *)ptr;
	must_eat_num = philo->system->must_eat;
	while (must_eat_num == -1 || philo->eat_cnt != must_eat_num)
	{
		if (check_state(philo))
			break ;
		eating(philo);
		if (check_state(philo))
			break ;
		sleeping(philo);
		if (check_state(philo))
			break ;
		thinking(philo);
	}

	return (0);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	message("has taken a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	message("has taken a fork", philo);
	message("is eating", philo);
	// ft_usleep(philo->system->time_to_eat);
	philo->last_eat = gettime();
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	// ft_usleep(philo->system->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	message("is thinking", philo);
	usleep(200);
}

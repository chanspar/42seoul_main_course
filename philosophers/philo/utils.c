/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:29:01 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/18 16:06:03 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > 9223372036854775807)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		str++;
	}
	return (num * sign);
}

void	flow_time(t_philo *philo, int wait_time)
{
	int	start_time;
	int	current_time;

	start_time = gettime();
	current_time = gettime();
	while (current_time - start_time < wait_time)
	{
		usleep(200);
		if (philo && )

	}

}

void	message(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->system->message);
	if (system_state(philo->system) == SHUTDOWN)
	{
		pthread_mutex_unlock(&philo->system->message);
		return ;
	}
	time = gettime - philo->system->time;
	printf("%d %d %s\n", time, philo->id, str);
	if (!ft_strcmp(str, "died"))
	{
		pthread_mutex_lock(&philo->system->lock);
		philo->system->state = SHUTDOWN;
		pthread_mutex_unlock(&philo->system->lock);
	}
	pthread_mutex_unlock(&philo->system->message);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

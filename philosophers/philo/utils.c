/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:29:01 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 20:09:15 by chanspar         ###   ########.fr       */
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
		if (num > 2147483647)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		str++;
	}
	return (num * sign);
}

void	ft_usleep(int wait, t_philo *philo)
{
	int	start;
	int	now;

	start = gettime();
	now = gettime();
	while (now - start < wait)
	{
		usleep(100);
		now = gettime();
		if (philo && check_state(philo))
			break ;
	}
}

void	message(char *str, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->system->message);
	if (system_state(philo->system) == OFF)
	{
		pthread_mutex_unlock(&philo->system->message);
		return ;
	}
	time = gettime() - philo->system->time;
	printf("%lld %d %s\n", time, philo->id, str);
	if (!ft_strcmp(str, "died"))
	{
		pthread_mutex_lock(&philo->system->lock);
		philo->system->state = OFF;
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

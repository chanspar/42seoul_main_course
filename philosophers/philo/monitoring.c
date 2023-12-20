#include "philo.h"

int system_state(t_system *system)
{
	int	state;

	pthread_mutex_lock(&system->lock);
	state = system->state;
	pthread_mutex_unlock(&system->lock);
	return (state);
}

int philo_state(t_philo *philo)
{
	int	time;

	time = gettime() - philo->life;
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

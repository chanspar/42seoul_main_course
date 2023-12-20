
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
		thinkin(philo);

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
	//ft_usleep 
	philo->life = gettime();
	philo->eat_cnt++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	sleeping(t_philo *philo)
{
	message("is sleeping", philo);
	//ft_usleep

}

void	thinking(t_philo *philo)
{
	message("is thinking", philo);
	usleep(200);
}

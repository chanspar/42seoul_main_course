#include "philo.h"

int	philo_case(t_system *system)
{
	int	i;

	if (system->num_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		//flow time
		printf("%d 1 died\n", system->time_to_die);
	}
	else
	{
		i = 0;
		while (i < system->num_philo)
		{
			if (pthread_create(&system->philos[i].thread, NULL, \
			thread_fuction, &system->philos[i]))
				return (1);
			i++;
		}

	}

}

void	*thread_fuction(void *ptr)
{
	t_philo	*philo;
	int		must_eat_num;

	philo = (t_philo *)ptr;
	must_eat_num = philo->system->must_eat;

}

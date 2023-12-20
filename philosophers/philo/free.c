#include "philo.h"

int free_mutex(t_system *system, int flag)
{
	pthread_mutex_destroy(&(system->message));
	if (flag == 1)
		return(err_print(E_MUTEXERR));

}

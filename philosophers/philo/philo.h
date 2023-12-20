/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:02:32 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/19 19:48:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ACTIVE 0
# define SHUTDOWN 1

typedef enum e_err
{
	E_ARGERR,
	E_NUMPHILOERR,
	E_TTDERR,
	E_TTEERR,
	E_TTSERR,
	E_MUSTEATERR,
	E_MALERR,
	E_MUTEXERR
}	t_err;

typedef struct s_system
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				state;
	int				time;
	pthread_mutex_t	message;
	pthread_mutex_t	lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_system;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_cnt;
	int				life;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_system		*system;
}	t_philo;

int		ft_atoi(const char *str);
int		arg_parse(t_system *system, int ac, char *av[]);
int		err_print(t_err err);
int		check_arg(t_system *system, int ac);
int		gettime(void);

int		set_env(t_system *system);
int		set_philos(t_system *system);
int		set_fork(t_system *system);

void	message(char *str, t_philo *philo);
int		ft_strcmp(char *s1, char *s2);

int		check_state(t_philo *philo);
int 	system_state(t_system *system);
int 	philo_state(t_philo *philo);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:02:32 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/23 15:43:17 by chanspar         ###   ########.fr       */
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

# define ON 0
# define OFF 1

typedef struct s_philo	t_philo;

typedef enum e_err
{
	e_argerr,
	e_numphiloerr,
	e_ttderr,
	e_tteerr,
	e_ttserr,
	e_musteaterr,
	e_malerr,
	e_mutexerr,
	e_threaderr,
	e_gettimeerr
}	t_err;

typedef struct s_system
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				state;
	long long		time;
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
	long long		last_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_system		*system;
}	t_philo;

int			ft_atoi(const char *str);
int			arg_parse(t_system *system, int ac, char *av[]);
int			err_print(t_err err);
int			check_arg(t_system *system, int ac);
long long	gettime(void);

int			set_env(t_system *system);
int			set_philos(t_system *system);
int			set_fork(t_system *system);

int			philo_case(t_system *system);
int			thread_exe(t_system *system);
int			thread_exe2(t_system *system);
void		*thread_action(void *ptr);
void		*thread_action2(void *ptr);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo, int time);

void		message(char *str, t_philo *philo);
int			ft_strcmp(char *s1, char *s2);
void		ft_usleep(int wait, t_philo *philo);
void		ft_onesleep(int wait);

int			check_state(t_philo *philo);
int			system_state(t_system *system);
int			philo_state(t_philo *philo);

int			free_system(t_system *system, int flag, t_err err, int idx);
void		free_all(t_system *system);

#endif

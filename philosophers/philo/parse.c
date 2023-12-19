/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:16:29 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:12 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_parse(t_system *system, int ac, char *av[])
{
	memset(system, 0, sizeof(t_system));
	system->num_philo = ft_atoi(av[1]);
	system->time_to_die = ft_atoi(av[2]);
	system->time_to_eat = ft_atoi(av[3]);
	system->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		system->must_eat = ft_atoi(av[5]);
	if (check_arg(system, ac) == 1)
		return (1);
	return (0);
}

int	check_arg(t_system *system, int ac)
{
	if (system->num_philo < 1)
		return (err_print(E_NUMPHILOERR));
	if (system->time_to_die < 1)
		return (err_print(E_TTDERR));
	if (system->time_to_eat < 1)
		return (err_print(E_TTEERR));
	if (system->time_to_sleep < 1)
		return (err_print(E_TTSERR));
	if (system->must_eat < 1 && ac == 6)
		return (err_print(E_MUSTEATERR));
	return (0);
}

int	set_env(t_system *system)
{
	if (set_philos(system) == 1)
		return (1);

}

int	set_philos(t_system *system)
{
	int	i;

	i = 0;
	system->philos = (t_philo *)malloc(sizeof(t_philo) * system->num_philo);
	if (!system->philos)
		return (err_print(E_MALERR));
	while (i < system->num_philo)
	{
		system->philos[i].id = i;
		system->philos[i].eat_cnt = 0;
		system->philos[i].life = 0; 
		system->philos[i].system = system;
		i++;
	}
	return (0);
}

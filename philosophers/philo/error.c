/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:11:09 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/21 18:20:05 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_print(t_err err)
{
	if (err == E_ARGERR)
		printf("The number of argument Error!!\n");
	else if (err == E_NUMPHILOERR)
		printf("The number of philosopher Error!!\n");
	else if (err == E_TTDERR)
		printf("You entered an incorrect time to die\n");
	else if (err == E_TTEERR)
		printf("You entered an incorrect time to eat\n");
	else if (err == E_TTSERR)
		printf("You entered an incorrect time to sleep\n");
	else if (err == E_MUSTEATERR)
		printf("You entered an incorrect must eat\n");
	else if (err == E_MALERR)
		printf("MAlloc fail!!");
	else if (err == E_MUTEXERR)
		printf("MUTEX error!!");
	else if (err == E_THREADERR)
		printf("Thread create error!!");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:11:09 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/23 14:59:47 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err_print(t_err err)
{
	if (err == e_argerr)
		printf("The number of argument Error!!\n");
	else if (err == e_numphiloerr)
		printf("The number of philosopher Error!!\n");
	else if (err == e_ttderr)
		printf("You entered an incorrect time to die\n");
	else if (err == e_tteerr)
		printf("You entered an incorrect time to eat\n");
	else if (err == e_ttserr)
		printf("You entered an incorrect time to sleep\n");
	else if (err == e_musteaterr)
		printf("You entered an incorrect must eat\n");
	else if (err == e_malerr)
		printf("MAlloc fail!!\n");
	else if (err == e_mutexerr)
		printf("MUTEX error!!\n");
	else if (err == e_threaderr)
		printf("Thread create error!!\n");
	else if (err == e_gettimeerr)
		printf("gettime error!!\n");
	return (1);
}

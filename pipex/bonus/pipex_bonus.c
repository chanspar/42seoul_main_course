/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:15:36 by chanspar          #+#    #+#             */
/*   Updated: 2023/09/22 17:01:17 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char *envp[])
{
	t_info	info;

	if (ac < 5)
	{
		write(1, "number of argument error\n", 25);
		exit(1);
	}
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac != 6)
		{
			write(1, "number of argument error\n", 25);
			exit(1);
		}
	}
	input_info_b(&info, av, envp);


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:15:47 by doukim            #+#    #+#             */
/*   Updated: 2024/01/30 19:33:52 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	isminus;
	int	idx;

	ret = 0;
	idx = 0;
	isminus = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
		isminus ^= (str[idx++] == '-');
	while (ft_isdigit(str[idx]))
		ret = (ret << 3) + (ret << 1) + str[idx++] - '0';
	if (isminus)
		return (-ret);
	return (ret);
}

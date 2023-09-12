/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:11:30 by chanspar          #+#    #+#             */
/*   Updated: 2023/08/29 17:24:44 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

long long	strlen_ft(const char *s);
char		*strchr_ft(const char *s, int c);
char		*strjoin_ft(char const *s1, char const *s2);
char		*strdup_ft(const char *s1);
char		*get_next_line(int fd);

#endif
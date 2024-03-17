/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 05:18:33 by doukim            #+#    #+#             */
/*   Updated: 2023/04/30 21:57:21 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	idx;

	if (!s)
		return (-1);
	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*gnl_strdup(char *s)
{
	size_t const	s_len = gnl_strlen(s);
	char			*newstr;
	size_t			idx;

	if (!s)
		return (NULL);
	newstr = (char *)malloc(s_len + 1);
	if (newstr == NULL)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		newstr[idx] = s[idx];
		idx++;
	}
	newstr[idx] = '\0';
	return (newstr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t const	s1_len = gnl_strlen(s1);
	size_t const	s2_len = gnl_strlen(s2);
	char			*newstr;
	size_t			idx1;
	size_t			idx2;

	newstr = (char *)malloc(s1_len + s2_len + 1);
	if (newstr == NULL || !s1 || !s2)
		return (NULL);
	idx1 = 0;
	idx2 = 0;
	while (s1[idx2])
		newstr[idx1++] = s1[idx2++];
	idx2 = 0;
	while (s2[idx2])
		newstr[idx1++] = s2[idx2++];
	newstr[idx1] = '\0';
	gnl_free_zero(&s1);
	gnl_free_zero(&s2);
	return (newstr);
}

char	*gnl_strchr(char **s, char c)
{
	size_t			s_len;
	size_t			idx;

	if (!*s)
		*s = gnl_strdup("");
	s_len = gnl_strlen(*s);
	idx = 0;
	while (idx < s_len && (*s)[idx] != c)
		idx++;
	if (idx < s_len)
		return (*s + idx);
	else
		return (NULL);
}

void	gnl_free_zero(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:45:00 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 19:24:44 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "ms_minishell.h"

typedef enum e_syntax
{
	NUL,
	WORD,
	PIPE,
	REDIRECTION,
	ROOT,
	LIST,
	PIPELINE,
	AND_IF,
	OR_IF,
	COMMAND,
	SIMPLE_COMMAND,
	REDIRECTION_LIST,
	SIMPLE_COMMAND_ELEMENT,
	SUBSHELL,
}	t_syntax;

#endif
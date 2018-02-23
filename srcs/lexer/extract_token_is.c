/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplementary_extract_token_bis.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:16:13 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:16:17 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_operator_token(t_lexer *lexer)
{
	if ((current_char(lexer->source) == '>'
		|| current_char(lexer->source) == '<')
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_blank_token(t_lexer *lexer)
{
	if (is_blank(current_char(lexer->source))
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_comma_token(t_lexer *lexer)
{
	if (current_char(lexer->source) == ';'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_pipe_token(t_lexer *lexer)
{
	if (current_char(lexer->source) == '|'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_eol_token(t_lexer *lexer)
{
	if (current_char(lexer->source) == '\n'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

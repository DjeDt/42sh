/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:15:50 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:17:31 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		routine_backslash(t_lexer *lexer)
{
	if (lexer->state->backslash == 0
		&& (lexer->state->dquotes == 0
		|| (peek_char(lexer->source) == '\\'
		|| peek_char(lexer->source) == '"'
		|| peek_char(lexer->source) == '\n'))
		&& lexer->state->squotes == 0)
	{
		lexer->state->backslash = 1;
		if (is_potential_quotes(next_char(lexer->source)))
			return (1);
	}
	return (0);
}

int		routine_dquotes(t_lexer *lexer)
{
	if (lexer->state->backslash == 0
		&& lexer->state->squotes == 0)
	{
		if (lexer->state->dquotes)
			lexer->state->dquotes = 0;
		else
			lexer->state->dquotes = 1;
		if (is_potential_quotes(next_char(lexer->source)))
			return (1);
	}
	return (0);
}

int		routine_squotes(t_lexer *lexer)
{
	if (lexer->state->backslash == 0
		&& lexer->state->dquotes == 0)
	{
		if (lexer->state->squotes)
			lexer->state->squotes = 0;
		else
			lexer->state->squotes = 1;
		if (is_potential_quotes(next_char(lexer->source)))
			return (1);
	}
	return (0);
}

int		change_quoting_state(t_lexer *lexer)
{
	char	c;

	c = current_char(lexer->source);
	if (c == '\\')
	{
		if (routine_backslash(lexer))
			return (0);
	}
	else if (c == '"')
	{
		if (routine_dquotes(lexer))
			return (0);
	}
	else if (c == '\'')
	{
		if (routine_squotes(lexer))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplementary_extract_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:16:02 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:18:13 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		routine_eol(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _EOL;
		next_char(lexer->source);
	}
	return (1);
}

int		routine_pipe(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _PIPE;
		next_char(lexer->source);
	}
	return (1);
}

int		routine_comma(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _SEP;
		next_char(lexer->source);
	}
	return (1);
}

int		routine_blank(t_token *token, t_lexer *lexer)
{
	if (token->type)
	{
		next_char(lexer->source);
		return (1);
	}
	else
		next_char(lexer->source);
	return (0);
}

int		routine_operator(t_token *token, t_lexer *lexer)
{
	if (token->type)
		return (1);
	else if (current_char(lexer->source) == '>')
		routine_operator_great(token, lexer);
	else if (current_char(lexer->source) == '<')
		routine_operator_less(token, lexer);
	next_char(lexer->source);
	return (1);
}

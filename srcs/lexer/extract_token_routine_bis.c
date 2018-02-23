/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplementary_extract_token_ter.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:16:27 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:50:26 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		routine_rest(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		if (ft_isdigit(current_char(lexer->source))
			&& !quoted(lexer->state)
			&& (peek_char(lexer->source) == '>'
			|| peek_char(lexer->source) == '<'))
			token->type = _IO_NUMBER;
		else
			token->type = _WORD;
	}
	if (lexer->state->backslash && current_char(lexer->source) == '\n')
	{
		if (!token->str)
			token->str = ft_strnew(2);
	}
	else
		token->str = append_char(token->str, current_char(lexer->source));
	next_char(lexer->source);
	lexer->state->backslash = 0;
	return (0);
}

void	routine_operator_great(t_token *token, t_lexer *lexer)
{
	if (peek_char(lexer->source) == '>')
	{
		token->type = _DGREAT;
		next_char(lexer->source);
	}
	else if (peek_char(lexer->source) == '&')
	{
		token->type = _DUP_OUTPUT;
		next_char(lexer->source);
	}
	else
		token->type = _GREAT;
	return ;
}

void	routine_operator_less(t_token *token, t_lexer *lexer)
{
	if (peek_char(lexer->source) == '<')
	{
		token->type = _DLESS;
		next_char(lexer->source);
	}
	else if (peek_char(lexer->source) == '&')
	{
		token->type = _DUP_INPUT;
		next_char(lexer->source);
	}
	else
		token->type = _LESS;
	return ;
}

int		routine_andif(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _AND_IF;
		next_char(lexer->source);
		next_char(lexer->source);
	}
	return (1);
}

int		routine_orif(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _OR_IF;
		next_char(lexer->source);
		next_char(lexer->source);
	}
	return (1);
}

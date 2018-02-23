/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_is_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:50:39 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:05:54 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_rest_token(t_lexer *lexer)
{
	lexer = (void *)lexer;
	return (1);
}

int		is_and_if_token(t_lexer *lexer)
{
	if (current_char(lexer->source) == '&'
		&& peek_char(lexer->source) == '&'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_or_if_token(t_lexer *lexer)
{
	if (current_char(lexer->source) == '|'
		&& peek_char(lexer->source) == '|'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_open_subshell(t_lexer *lexer)
{
	if (current_char(lexer->source) == '('
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

int		is_close_subshell(t_lexer *lexer)
{
	if (current_char(lexer->source) == ')'
		&& !quoted(lexer->state))
		return (1);
	else
		return (0);
}

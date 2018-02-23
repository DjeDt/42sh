/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_routine_ter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:05:28 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:05:31 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		routine_open_subshell(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _OPEN_SUBSHELL;
		next_char(lexer->source);
	}
	return (1);
}

int		routine_close_subshell(t_token *token, t_lexer *lexer)
{
	if (token->type == 0)
	{
		token->type = _CLOSE_SUBSHELL;
		next_char(lexer->source);
	}
	return (1);
}

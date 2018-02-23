/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_supplementary_bis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:22:33 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 12:22:36 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_redirect_op(int type)
{
	if (type == _LESS || type == _GREAT || type == _DLESS || type == _DGREAT
		|| type == _DUP_OUTPUT || type == _DUP_INPUT)
		return (1);
	else
		return (0);
}

int			is_end_command(t_lexer *lexer)
{
	if (lexer->current_token->type == _PIPE
		|| lexer->current_token->type == _AND_IF
		|| lexer->current_token->type == _OR_IF
		|| lexer->current_token->type == _SEP
		|| lexer->current_token->type == _EOL
		|| lexer->current_token->type == _EOF)
	{
		return (1);
	}
	else
		return (0);
}

int			is_end_pipeline(t_lexer *lexer)
{
	if (lexer->current_token->type == _AND_IF
		|| lexer->current_token->type == _OR_IF
		|| lexer->current_token->type == _SEP
		|| lexer->current_token->type == _EOL
		|| lexer->current_token->type == _EOF)
	{
		return (1);
	}
	else
		return (0);
}

int			is_end_and_or(t_lexer *lexer)
{
	if (lexer->current_token->type == _SEP
		|| lexer->current_token->type == _EOL
		|| lexer->current_token->type == _EOF)
	{
		return (1);
	}
	else
		return (0);
}

int			is_start_command(t_lexer *lexer)
{
	if (lexer->current_token->type == _WORD
		|| lexer->current_token->type == _IO_NUMBER
		|| lexer->current_token->type == _GREAT
		|| lexer->current_token->type == _LESS
		|| lexer->current_token->type == _DGREAT
		|| lexer->current_token->type == _DLESS
		|| lexer->current_token->type == _DUP_OUTPUT
		|| lexer->current_token->type == _DUP_INPUT
		|| lexer->current_token->type == _OPEN_SUBSHELL)
	{
		return (1);
	}
	else
		return (0);
}

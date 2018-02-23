/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_supplementary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:21:40 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 12:21:41 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_icode		*parse_command(t_lexer *lexer, t_shell *shell)
{
	t_icode		*node;

	if (lexer->current_token->type == _OPEN_SUBSHELL)
		node = parse_subshell(lexer, shell);
	else
		node = parse_simple_command(lexer, shell);
	return (node);
}

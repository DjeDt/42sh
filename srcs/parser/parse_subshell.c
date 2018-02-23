/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:53:24 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/08/16 09:42:14 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		routine_add_child(t_icode *rl_node, t_lexer *lexer)
{
	t_icode		*node;

	if (TOKEN_TYPE == _IO_NUMBER || TOKEN_TYPE == _WORD)
		node = allocate_node(TOKEN_TYPE, ft_strdup(TOKEN_STR));
	else
		node = allocate_node(TOKEN_TYPE, NULL);
	add_child(rl_node, node);
	next_token(lexer);
	return ;
}

t_icode		*parse_redirect_list(t_lexer *lexer, t_shell *shell)
{
	t_icode		*rl_node;

	rl_node = allocate_node(_REDIRECT_LIST, NULL);
	while (!is_end_command(lexer))
	{
		if (TOKEN_TYPE == _IO_NUMBER)
			routine_add_child(rl_node, lexer);
		else if (is_redirect_op(TOKEN_TYPE))
		{
			routine_add_child(rl_node, lexer);
			if (TOKEN_TYPE == _WORD)
				routine_add_child(rl_node, lexer);
			else
			{
				add_unexpected_token(lexer, shell);
				return (rl_node);
			}
		}
		else
			return (rl_node);
	}
	create_heredoc(rl_node, shell);
	return (rl_node);
}

t_icode		*parse_subshell(t_lexer *lexer, t_shell *shell)
{
	t_icode		*subshell_node;
	t_icode		*node;

	next_token(lexer);
	subshell_node = allocate_node(_SUBSHELL, NULL);
	node = parse_list(lexer, shell);
	add_child(subshell_node, node);
	if (lexer->current_token->type == _CLOSE_SUBSHELL)
		next_token(lexer);
	else
	{
		add_unexpected_token(lexer, shell);
		return (subshell_node);
	}
	node = parse_redirect_list(lexer, shell);
	add_child(subshell_node, node);
	return (subshell_node);
}

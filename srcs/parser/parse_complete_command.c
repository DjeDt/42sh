/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_complete_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:20:12 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:03:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_icode		*parse_simple_command(t_lexer *lexer, t_shell *shell)
{
	t_icode		*node_simple_command;
	t_icode		*node;

	node_simple_command = allocate_node(_SIMPLE_COMMAND, NULL);
	while (!is_end_command(lexer))
	{
		if (TOKEN_TYPE == _IO_NUMBER || TOKEN_TYPE == _WORD)
		{
			node = allocate_node(TOKEN_TYPE, ft_strdup(TOKEN_STR));
			add_child(node_simple_command, node);
		}
		else if (is_redirect_op(TOKEN_TYPE))
		{
			node = allocate_node(TOKEN_TYPE, NULL);
			add_child(node_simple_command, node);
		}
		else
		{
			init_type_do_heredoc(node_simple_command, shell);
			return (node_simple_command);
		}
		next_token(lexer);
	}
	init_type_do_heredoc(node_simple_command, shell);
	return (node_simple_command);
}

t_icode		*parse_pipeline(t_lexer *lexer, t_shell *shell)
{
	t_icode		*node_pipeline;
	t_icode		*node;

	node_pipeline = allocate_node(_PIPE, NULL);
	while (!is_end_pipeline(lexer))
	{
		if (is_start_command(lexer))
		{
			node = parse_command(lexer, shell);
			add_child(node_pipeline, node);
			if (TOKEN_TYPE == _PIPE)
			{
				next_token(lexer);
				if (is_end_pipeline(lexer))
					add_unexpected_token(lexer, shell);
			}
			else if (is_start_command(lexer))
				add_unexpected_token(lexer, shell);
		}
		else
			return (node_pipeline);
	}
	return (node_pipeline);
}

t_icode		*parse_and_or(t_lexer *lexer, t_shell *shell)
{
	t_icode		*and_or_node;
	t_icode		*node;

	and_or_node = allocate_node(_AND_OR, NULL);
	while (!is_end_and_or(lexer))
	{
		if (is_start_command(lexer))
		{
			node = parse_pipeline(lexer, shell);
			add_child(and_or_node, node);
			if (TOKEN_TYPE == _AND_IF
				|| TOKEN_TYPE == _OR_IF)
			{
				node = allocate_node(TOKEN_TYPE, NULL);
				add_child(and_or_node, node);
				next_token(lexer);
				if (is_end_and_or(lexer))
					add_unexpected_token(lexer, shell);
			}
		}
		else
			return (and_or_node);
	}
	return (and_or_node);
}

t_icode		*parse_list(t_lexer *lexer, t_shell *shell)
{
	t_icode		*list_node;
	t_icode		*node;

	list_node = allocate_node(_LIST, NULL);
	while (TOKEN_TYPE != _EOL
			&& TOKEN_TYPE != _EOF)
	{
		if (is_start_command(lexer))
		{
			node = parse_and_or(lexer, shell);
			add_child(list_node, node);
			if (TOKEN_TYPE == _SEP)
				next_token(lexer);
		}
		else
			return (list_node);
	}
	return (list_node);
}

t_icode		*parse_complete_command(t_lexer *lexer, t_shell *shell)
{
	t_icode		*complete_command_node;
	t_icode		*node;

	current_token(lexer);
	complete_command_node = allocate_node(_COMPLETE_COMMAND, NULL);
	while (TOKEN_TYPE != _EOL
			&& TOKEN_TYPE != _EOF)
	{
		if (is_start_command(lexer))
		{
			node = parse_list(lexer, shell);
			add_child(complete_command_node, node);
		}
		else
		{
			add_unexpected_token(lexer, shell);
			return (complete_command_node);
		}
	}
	if (TOKEN_TYPE == _EOL)
		next_token(lexer);
	return (complete_command_node);
}

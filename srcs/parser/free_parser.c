/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:19:07 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:19:12 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		free_tab(char **tab_cmd)
{
	int		i;

	if (!tab_cmd)
		return ;
	i = 0;
	while (tab_cmd[i])
	{
		free(tab_cmd[i]);
		i++;
	}
	free(tab_cmd);
	return ;
}

void		free_simple_command(t_icode *simple_command)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < simple_command->nb_children)
	{
		current = simple_command->children[i];
		if (current->value)
			free(current->value);
		free(current);
		i++;
	}
	if (simple_command->children)
		free(simple_command->children);
	if (simple_command->command)
		free_tab(simple_command->command);
	if (simple_command->heredoc)
		free_tab(simple_command->heredoc);
	free(simple_command);
	return ;
}

void		free_pipe_seq(t_icode *pipe_seq)
{
	int		i;

	i = 0;
	while (i < pipe_seq->nb_children)
	{
		free_simple_command(pipe_seq->children[i]);
		i++;
	}
	if (pipe_seq->children)
		free(pipe_seq->children);
	free(pipe_seq);
	return ;
}

void		free_parse_tree(t_icode *root)
{
	int			i;

	i = 0;
	while (i < root->nb_children)
	{
		free_parse_tree(root->children[i]);
		i++;
	}
	if (root->children)
		free(root->children);
	if (root->value)
		free(root->value);
	if (root->command)
		free_tab(root->command);
	if (root->heredoc)
		free_tab(root->heredoc);
	free(root);
	return ;
}

void		free_parser(t_parser *parser)
{
	t_lexer		*lexer;

	lexer = parser->lexer;
	if (TOKEN_TYPE == _EOF || parser->nb_error)
	{
		lexer->current_token->type = 0;
		clean_source(lexer->source);
	}
	free_parse_tree(parser->tree);
	parser->tree = NULL;
	free_error_list(parser);
	return ;
}

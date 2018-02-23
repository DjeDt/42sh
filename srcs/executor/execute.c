/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:13:56 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:45:03 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		execute_pipe_seq(t_icode *root, int read_pipe, int i, t_shell *s)
{
	int			pid;
	int			pipe_array[2];

	if (i == root->nb_children)
		return ;
	pipe(pipe_array);
	pid = fork();
	if (pid == 0)
	{
		routine_pipe_child(pipe_array, i, read_pipe, root);
		execute_command(root, i, s);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (read_pipe != STDIN_FILENO)
			close(read_pipe);
		close(pipe_array[1]);
		execute_pipe_seq(root, pipe_array[0], i + 1, s);
		close(pipe_array[0]);
		wait_function(pid, s);
	}
	return ;
}

void		execute_and_or(t_icode *root, t_shell *shell)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < root->nb_children)
	{
		current = root->children[i];
		if (current->type == _AND_IF)
		{
			if (shell->executor->exit_code)
				i++;
		}
		else if (current->type == _OR_IF)
		{
			if (shell->executor->exit_code == 0)
				i++;
		}
		else if (current->nb_children == 1
				&& current->children[0]->command_type & _BUILT_IN)
			execute_simple_command(current->children[0], shell);
		else
			execute_pipe_seq(current, 0, 0, shell);
		i++;
	}
	return ;
}

void		execute_list(t_icode *root, t_shell *shell)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < root->nb_children)
	{
		current = root->children[i];
		if (current->type == _AND_OR)
			execute_and_or(current, shell);
		else
		{
			ft_putstr_fd("42sh: Please report this error...", 2);
			return ;
		}
		i++;
	}
	return ;
}

void		execute_complete_command(t_icode *root, t_shell *shell)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < root->nb_children)
	{
		current = root->children[i];
		if (current->type == _LIST)
			execute_list(current, shell);
		else
		{
			ft_putstr_fd("42sh: Please report this error...", 2);
			return ;
		}
		i++;
	}
	return ;
}

void		execute(t_shell *shell)
{
	if (shell->parser->error == NULL)
		execute_complete_command(shell->parser->tree, shell);
	else
		print_parse_error(shell->parser);
	return ;
}

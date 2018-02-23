/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type_do_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:19:27 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:22:12 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_builtin(t_icode *simple_command)
{
	char	*cmd;

	cmd = simple_command->command[0];
	if (ft_strcmp(cmd, "cd") == 0 && ft_strlen(cmd) == 2)
		simple_command->command_type |= _CD;
	else if (ft_strcmp(cmd, "exit") == 0 && ft_strlen(cmd) == 4)
		simple_command->command_type |= _EXIT;
	else if (ft_strcmp(cmd, "env") == 0 && ft_strlen(cmd) == 3)
		simple_command->command_type |= _ENV;
	else if (ft_strcmp(cmd, "setenv") == 0 && ft_strlen(cmd) == 6)
		simple_command->command_type |= _SETENV;
	else if (ft_strcmp(cmd, "unsetenv") == 0 && ft_strlen(cmd) == 8)
		simple_command->command_type |= _UNSETENV;
	else if (ft_strcmp(cmd, "echo") == 0 && ft_strlen(cmd) == 4)
		simple_command->command_type |= _ECHO;
	if (simple_command->command_type == 0)
		return (0);
	else
		return (1);
}

char		**get_command(t_icode *simple_command)
{
	char		**cmd;
	char		**walk;
	t_icode		*current;
	int			i;

	cmd = (char **)malloc(sizeof(char *) * (simple_command->nb_children + 1));
	if (!cmd)
		exit_routine();
	walk = cmd;
	i = 0;
	while (i < simple_command->nb_children)
	{
		current = simple_command->children[i];
		if (current->hidden == 0)
		{
			if ((*walk = ft_strdup(current->value)) == NULL)
				exit_routine();
			walk++;
		}
		i++;
	}
	*walk = NULL;
	return (cmd);
}

void		create_heredoc(t_icode *simple_command, t_shell *shell)
{
	t_icode		*word;
	char		*line;
	int			i;

	i = 0;
	while (i < simple_command->nb_children)
	{
		if (simple_command->children[i]->type == _DLESS)
		{
			word = simple_command->children[i + 1];
			while ((line = ft_read_line("heredoc> ", NULL_CTRLD))
					&& (ft_strncmp(line, word->value, ft_strlen(word->value))
					|| (ft_strlen(line) != (ft_strlen(word->value) + 1))))
				if (routine_create_heredoc(simple_command, line, shell))
					return ;
			if (line)
				ft_strdel(&line);
		}
		i++;
	}
	return ;
}

void		loop_init_type(t_icode *simple_command, t_shell *shell)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < simple_command->nb_children)
	{
		current = simple_command->children[i];
		if (current->type == _IO_NUMBER || is_redirect_op(current->type))
		{
			current->hidden = 1;
			if (is_redirect_op(current->type))
			{
				if ((i + 1) < simple_command->nb_children
					&& simple_command->children[i + 1]->type == _WORD)
				{
					simple_command->children[i + 1]->hidden = 1;
					i++;
				}
				else
					add_error("42sh: parse error in redirect", shell->parser);
			}
		}
		i++;
	}
	return ;
}

void		init_type_do_heredoc(t_icode *simple_command, t_shell *shell)
{
	loop_init_type(simple_command, shell);
	simple_command->command = get_command(simple_command);
	if (simple_command->command[0] == NULL)
		add_error("42sh: Invalid null command", shell->parser);
	else if (is_builtin(simple_command))
		simple_command->command_type |= _BUILT_IN;
	else
		simple_command->command_type |= _BINARY;
	if (shell->parser->error == 0)
		create_heredoc(simple_command, shell);
	return ;
}

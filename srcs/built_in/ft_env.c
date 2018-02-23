/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:12:34 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:48:44 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define CLEAR_ENV 2

static int		get_options(int *options, char **command)
{
	int		i;
	int		j;

	i = 1;
	while (command[i] && command[i][0] == '-')
	{
		j = 1;
		while (command[i][j])
		{
			if (command[i][j] == 'i')
				*options |= CLEAR_ENV;
			else
			{
				error_env(command[i][j]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}

static int		modify_env(char **cmd, int options, int cmd_index, t_shell *s)
{
	int		i;

	if (options & CLEAR_ENV)
		clear_env(s);
	i = cmd_index;
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		ft_putenv(cmd[i], s);
		i++;
	}
	return (i);
}

static void		routine_noexec_env(t_shell *shell)
{
	ft_print_env(shell);
	exit(EXIT_SUCCESS);
	return ;
}

static void		routine_exec_env(char **command, int cmd_index, t_shell *shell)
{
	command[cmd_index] = find_command(command[cmd_index], shell);
	execve(command[cmd_index], &(command[cmd_index]), shell->env);
	ft_putendl_fd("42sh: env: No such file or directory", 2);
	exit(EXIT_FAILURE);
	return ;
}

void			ft_env(char **command, t_shell *shell)
{
	int		cmd_index;
	int		options;
	int		pid;

	pid = fork();
	if (!pid)
	{
		options = 0;
		if ((cmd_index = get_options(&options, command)) == -1)
		{
			shell->executor->exit_code = -1;
			return ;
		}
		cmd_index = modify_env(command, options, cmd_index, shell);
		if (command[cmd_index])
			routine_exec_env(command, cmd_index, shell);
		else
			routine_noexec_env(shell);
	}
	else
		wait_function(pid, shell);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:14:09 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:58:40 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		wait_function(int pid, t_shell *shell)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->executor->exit_code = WEXITSTATUS(status);
	return ;
}

void		launch_builtin(t_icode *simple_command, t_shell *shell)
{
	if (simple_command->command_type & _CD)
		ft_cd(simple_command->command, shell);
	else if (simple_command->command_type & _EXIT)
		exit_built_in(simple_command->command, shell);
	else if (simple_command->command_type & _ENV)
		ft_env(simple_command->command, shell);
	else if (simple_command->command_type & _SETENV)
		ft_setenv(simple_command->command, shell);
	else if (simple_command->command_type & _UNSETENV)
		ft_unsetenv(simple_command->command, shell);
	else if (simple_command->command_type & _ECHO)
		ft_echo(simple_command->command, shell);
	return ;
}

void		routine_exec(t_icode *simple_command, t_shell *shell)
{
	char	**command;

	command = simple_command->command;
	if (shell->executor->error)
	{
		print_exec_error(shell->executor);
		return ;
	}
	if (simple_command->command_type & _BUILT_IN)
		launch_builtin(simple_command, shell);
	else if (simple_command->command_type & _BINARY)
	{
		if (!ft_strchr(*command, '/'))
			*command = find_command(*command, shell);
		execve(*command, command, shell->env);
		ft_putstr_fd("42sh: command not found: ", 2);
		ft_putendl_fd(*command, 2);
	}
	else
		ft_putendl_fd("42sh: no command type", 2);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_executor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:13:37 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:39:45 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			print_exec_error(t_exec *exec)
{
	int		i;

	i = 0;
	while (i < exec->nb_err)
	{
		ft_putendl_fd(exec->error[i], 2);
		i++;
	}
}

void			add_error_exec(char *error_msg, t_exec *e)
{
	char	**err;

	err = (char **)malloc(sizeof(char *) * (e->nb_err + 1));
	if (!err)
		exit_routine();
	if (e->error)
	{
		ft_memcpy((void *)err, (void *)e->error, (sizeof(char *) * e->nb_err));
		free(e->error);
	}
	if ((err[e->nb_err++] = ft_strdup(error_msg)) == NULL)
		exit_routine();
	e->error = err;
}

void			free_executor(t_exec *exec)
{
	int		i;

	i = 0;
	while (i < exec->nb_err)
	{
		ft_strdel(&exec->error[i]);
		i++;
	}
	free(exec->error);
	exec->nb_err = 0;
	exec->error = NULL;
	dup2(get_term_fd(STDIN_FILENO), STDIN_FILENO);
	dup2(get_term_fd(STDOUT_FILENO), STDOUT_FILENO);
	dup2(get_term_fd(STDERR_FILENO), STDERR_FILENO);
}

t_exec			*allocate_executor(void)
{
	t_exec	*exec;

	exec = (t_exec *)malloc(sizeof(t_exec));
	if (!exec)
		exit_routine();
	exec->error = NULL;
	exec->exit_code = 0;
	exec->nb_err = 0;
	return (exec);
}

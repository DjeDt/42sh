/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:38:51 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:56:14 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				get_term_fd(int flag)
{
	static int		stdin = -1;
	static int		stdout = -1;
	static int		stderr = -1;

	if (stdin == -1 || stdout == -1 || stderr == -1)
	{
		stdin = dup2(STDIN_FILENO, 10);
		stdout = dup2(STDOUT_FILENO, 11);
		stderr = dup2(STDERR_FILENO, 12);
	}
	if (flag == STDIN_FILENO)
		return (stdin);
	else if (flag == STDOUT_FILENO)
		return (stdout);
	else if (flag == STDERR_FILENO)
		return (stderr);
	return (-1);
}

char			**copy_env(char **envp, t_shell *shell)
{
	char	**env;
	int		len;
	int		i;

	len = 0;
	while (envp[len])
		len++;
	shell->nb_var_env = len;
	env = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	if (!env)
		exit_routine();
	i = 0;
	while (i < len)
	{
		if ((env[i] = ft_strdup(envp[i])) == NULL)
			exit_routine();
		i++;
	}
	env[i] = NULL;
	return (env);
}

void			free_shell(t_shell *shell)
{
	free(*(shell->env));
	return ;
}

static void		init_shell_supplementary(t_shell *shell)
{
	char	*s;
	char	*l;
	int		nb;

	if ((s = get_env("SHLVL", shell)))
	{
		nb = ft_atoi(s) + 1;
		if ((s = ft_itoa(nb)) == NULL)
			exit_routine();
		if ((l = ft_strjoin("SHLVL=", s)) == NULL)
			exit_routine();
		free(s);
	}
	else
		l = ft_strdup("SHLVL=1");
	ft_putenv(l, shell);
	free(l);
	return ;
}

t_shell			*allocate_shell(int ac, char **av, char *envp[])
{
	t_shell		*shell;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (!shell)
		exit_routine();
	shell->env = copy_env(envp, shell);
	shell->term_fd = get_term_fd(STDIN_FILENO);
	init_shell_supplementary(shell);
	if (ac > 1)
	{
		shell->file_fd = open(av[1], O_RDONLY);
		if (shell->file_fd == -1)
		{
			ft_putendl_fd("42sh: could not open the file", shell->term_fd);
			exit(EXIT_FAILURE);
		}
	}
	else
		shell->file_fd = -1;
	shell->parser = allocate_parser(shell);
	shell->executor = allocate_executor();
	return (shell);
}

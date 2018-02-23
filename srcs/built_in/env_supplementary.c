/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_supplementary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:09:56 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:28:35 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		ft_putenv_supplementary(char *line, int i, t_shell *shell)
{
	char	**new_env;
	char	**e;

	e = shell->env;
	new_env = (char **)malloc(sizeof(char *) * (++shell->nb_var_env + 1));
	if (!new_env)
		exit_routine();
	ft_memcpy(new_env, e, sizeof(char *) * i);
	if ((new_env[i] = ft_strdup(line)) == NULL)
		exit_routine();
	new_env[i + 1] = 0;
	free(e);
	shell->env = new_env;
	return ;
}

void			ft_putenv(char *line, t_shell *shell)
{
	char	**e;
	int		i;

	e = shell->env;
	i = 0;
	while (i < shell->nb_var_env)
	{
		if (ft_strncmp(e[i], line, (ft_strchr(e[i], '=') - e[i])) == 0
			&& (ft_strchr(e[i], '=') - e[i]) == (ft_strchr(line, '=') - line))
		{
			free(e[i]);
			if ((e[i] = ft_strdup(line)) == NULL)
				exit_routine();
			return ;
		}
		i++;
	}
	ft_putenv_supplementary(line, i, shell);
	return ;
}

void			ft_print_env(t_shell *shell)
{
	char	**env;
	int		i;

	env = shell->env;
	i = 0;
	while (i < shell->nb_var_env)
		ft_putendl(env[i++]);
	return ;
}

void			clear_env(t_shell *shell)
{
	int		i;
	char	**env;

	env = shell->env;
	i = 0;
	while (i < shell->nb_var_env)
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	if (shell->env)
	{
		free(shell->env);
		shell->env = NULL;
	}
	shell->nb_var_env = 0;
	return ;
}

char			*get_env(char *env_name, t_shell *shell)
{
	char	**e;
	char	*tmp;
	int		i;

	e = shell->env;
	i = 0;
	while (i < shell->nb_var_env)
	{
		if (ft_strncmp(e[i], env_name, (ft_strchr(e[i], '=') - e[i])) == 0
			&& (size_t)(ft_strchr(e[i], '=') - e[i]) == ft_strlen(env_name))
		{
			tmp = ft_strchr(e[i], '=') + 1;
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

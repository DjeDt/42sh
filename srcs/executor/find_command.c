/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:14:17 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/18 10:01:15 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			**loop_path(char **env)
{
	char	**path_tab;
	char	*path_line;
	int		i;

	path_tab = NULL;
	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_line = env[i];
			path_tab = ft_strsplit(&path_line[5], ':');
			if (!path_tab)
				exit_routine();
		}
		i++;
	}
	return (path_tab);
}

static int		find_command_supplementary(char **p, char *s, char *cmd, int i)
{
	ft_strcat(s, p[i]);
	ft_strcat(s, "/");
	ft_strcat(s, cmd);
	if (access(s, X_OK) == 0)
	{
		free(cmd);
		free_tab(p);
		return (1);
	}
	else
		free(s);
	return (0);
}

char			*find_command(char *cmd, t_shell *shell)
{
	char	*s;
	char	**p;
	int		i;

	p = loop_path(shell->env);
	i = 0;
	s = NULL;
	while (p && p[i])
	{
		s = ft_memalloc(sizeof(char) * (ft_strlen(p[i]) + ft_strlen(cmd) + 2));
		if (!s)
			exit_routine();
		if (find_command_supplementary(p, s, cmd, i))
			return (s);
		i++;
	}
	free_tab(p);
	return (cmd);
}

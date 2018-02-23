/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:13:07 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:13:09 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		loop_unsetenv(char **cmd, t_shell *shell)
{
	char	**e;
	int		i;
	int		j;
	int		offset;

	e = shell->env;
	i = 1;
	while (cmd[i])
	{
		j = 0;
		while (e[j])
		{
			if (ft_strncmp(e[j], cmd[i], (ft_strchr(e[j], '=') - e[j])) == 0
				&& ((size_t)(ft_strchr(e[j], '=') - e[j]) == ft_strlen(cmd[i])))
			{
				free(e[j]);
				offset = (shell->nb_var_env--) - (j + 1);
				ft_memmove(&e[j], &e[j + 1], sizeof(char *) * offset);
				e[shell->nb_var_env] = 0;
			}
			j++;
		}
		i++;
	}
	return ;
}

void			ft_unsetenv(char **command, t_shell *shell)
{
	if (!command[1])
	{
		ft_putendl_fd("42sh: unsetenv: no args", 2);
		shell->executor->exit_code = -1;
		return ;
	}
	loop_unsetenv(command, shell);
	shell->executor->exit_code = 0;
	return ;
}

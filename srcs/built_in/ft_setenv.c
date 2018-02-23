/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:12:55 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:12:58 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_setenv(char **command, t_shell *shell)
{
	int		i;

	if (!command[1])
	{
		ft_print_env(shell);
		return ;
	}
	i = 1;
	while (command[i])
	{
		if (!ft_strchr(command[i], '='))
		{
			ft_putendl_fd("42sh: setenv: args must contain equal sign", 2);
			shell->executor->exit_code = -1;
			return ;
		}
		else
			ft_putenv(command[i], shell);
		i++;
	}
	shell->executor->exit_code = 0;
	return ;
}

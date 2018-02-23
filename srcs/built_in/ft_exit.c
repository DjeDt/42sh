/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:28:47 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:28:48 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		exit_built_in(char **command, t_shell *shell)
{
	int		status;

	command++;
	status = 0;
	(void)shell;
	if (*command)
		status = ft_atoi(*command);
	exit(status);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:36:22 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/20 08:53:21 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		**realloc_tab(char **tab_str, int size)
{
	char	**new;

	if ((new = (char **)ft_memalloc(sizeof(char *) * size)) == NULL)
		exit_routine();
	ft_memcpy((void *)(new + 1), (void *)tab_str, sizeof(char *) * (size - 2));
	free(tab_str);
	return (new);
}

void		exit_routine(void)
{
	default_terminal_mode();
	ft_putendl_fd("42sh: fatal error, quitting...", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

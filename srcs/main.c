/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:18:27 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/18 10:01:31 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main(int ac, char **argv, char *envp[])
{
	t_shell		*shell;

	main_signal();
	shell = allocate_shell(ac, argv, envp);
	while (42)
	{
		parse(shell);
		execute(shell);
		free_parser(shell->parser);
		free_executor(shell->executor);
	}
	return (0);
}

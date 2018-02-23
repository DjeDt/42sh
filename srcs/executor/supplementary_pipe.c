/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supplementary_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:14:47 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:14:52 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	routine_pipe_child(int pipe[2], int i, int read_pipe, t_icode *root)
{
	child_signal();
	if (read_pipe != STDIN_FILENO)
	{
		dup2(read_pipe, STDIN_FILENO);
		close(read_pipe);
	}
	if ((i + 1) < root->nb_children)
		dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	close(pipe[0]);
}

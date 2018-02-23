/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_supplementary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:06:59 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:44:37 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		execute_command(t_icode *root, int index, t_shell *s)
{
	if ((root->children)[index]->type == _SUBSHELL)
		execute_subshell((root->children)[index], s);
	else
		execute_simple_command((root->children)[index], s);
	return ;
}

void		execute_simple_command(t_icode *simple_command, t_shell *shell)
{
	t_icode		*current;
	int			i;

	i = 0;
	while (i < simple_command->nb_children)
	{
		current = simple_command->children[i];
		if (is_redirect_op(current->type))
			redirect(simple_command, i, shell);
		i++;
	}
	routine_exec(simple_command, shell);
	return ;
}

void		execute_subshell(t_icode *subshell, t_shell *shell)
{
	t_icode		*rl_node;
	int			i;

	if (subshell->nb_children == 2)
	{
		rl_node = subshell->children[1];
		i = 0;
		while (i < rl_node->nb_children)
		{
			if (is_redirect_op(rl_node->children[i]->type))
				redirect(rl_node, i, shell);
			i++;
		}
	}
	execute_list(subshell->children[0], shell);
	exit(shell->executor->exit_code);
}

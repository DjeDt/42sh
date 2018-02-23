/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:19:42 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:19:44 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		add_child(t_icode *p, t_icode *child)
{
	t_icode		**n;
	int			nb;

	nb = p->nb_children;
	n = (t_icode **)ft_memalloc(sizeof(t_icode *) * (nb + 1));
	if (!n)
		exit_routine();
	if (p->children)
	{
		ft_memcpy((void *)n, (void *)p->children, (sizeof(t_icode *) * nb));
		free(p->children);
	}
	n[(p->nb_children)++] = child;
	p->children = n;
	return ;
}

t_icode		*allocate_node(int type, char *value)
{
	t_icode		*icode_node;

	icode_node = (t_icode *)ft_memalloc(sizeof(t_icode));
	if (!icode_node)
		exit_routine();
	icode_node->type = type;
	icode_node->value = value;
	icode_node->command_type = 0;
	icode_node->command = NULL;
	icode_node->hidden = 0;
	icode_node->nb_children = 0;
	icode_node->children = NULL;
	icode_node->heredoc = NULL;
	icode_node->nb_heredoc = 0;
	return (icode_node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_supplementary.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:19:19 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:19:21 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		heredoc_add_line(t_icode *simple_command, char *line)
{
	char	**n;
	char	**p;
	int		*len;

	len = &(simple_command->nb_heredoc);
	p = simple_command->heredoc;
	n = (char **)ft_memalloc(sizeof(char *) * (*len + 2));
	if (!n)
		exit_routine();
	ft_memcpy((void *)n, (void *)p, sizeof(char *) * *len);
	if ((n[(*len)++] = ft_strdup(line)) == NULL)
		exit_routine();
	n[*len] = NULL;
	free(simple_command->heredoc);
	simple_command->heredoc = n;
	return ;
}

int				routine_create_heredoc(t_icode *sc, char *l, t_shell *s)
{
	if (!(*l))
	{
		ft_strdel(&l);
		add_error("", s->parser);
		return (1);
	}
	heredoc_add_line(sc, l);
	ft_strdel(&l);
	return (0);
}

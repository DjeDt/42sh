/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:23:11 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/20 08:54:12 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			ft_historic(t_line *l, int flags)
{
	static char		**historic = NULL;
	char			*line;
	int				len;

	if (!historic)
		if ((historic = (char **)ft_memalloc(sizeof(char *) * 2)) == NULL)
			exit_routine();
	len = 0;
	while (historic[len])
		len++;
	if (flags == INIT)
	{
		l->historic = historic;
		l->len_historic = len;
		l->current_historic = -1;
	}
	else if ((flags == ADD) && *(l->line) && *(l->line) != '\n')
	{
		line = l->line;
		historic = realloc_tab(historic, len + 2);
		if ((historic[0] = ft_strdup(line)) == NULL)
			exit_routine();
		historic[len + 1] = 0;
	}
	return ;
}

static void		routine_reset_line(t_line *line_struct)
{
	free(line_struct->line);
	line_struct->size = BUF_SIZE;
	line_struct->nb_char = 0;
	line_struct->cursor_pos = 0;
	if ((line_struct->line = (char *)ft_memalloc(BUF_SIZE)) == NULL)
		exit_routine();
	update_term(line_struct, CLEAR_NEEDED);
	return ;
}

static void		routine_set_line(t_line *line_struct, int *c)
{
	char		*l;
	int			len;

	l = (line_struct->historic)[*c];
	len = ft_strlen(l);
	free(line_struct->line);
	if ((line_struct->line = (char *)ft_memalloc(sizeof(char) * len)) == NULL)
		exit_routine();
	ft_memcpy((void *)line_struct->line, (void *)l, sizeof(char) * (len - 1));
	line_struct->nb_char = (len - 1);
	line_struct->cursor_pos = (len - 1);
	line_struct->size = len;
	update_term(line_struct, CLEAR_NEEDED);
	return ;
}

int				up_historic(t_line *line_struct, int flags)
{
	int				*c;

	if ((flags & HISTORIC) == 0)
		return (1);
	c = &(line_struct->current_historic);
	(*c)++;
	if (*c < line_struct->len_historic)
		routine_set_line(line_struct, c);
	else
	{
		*c = line_struct->len_historic;
		routine_reset_line(line_struct);
	}
	return (1);
}

int				down_historic(t_line *line_struct, int flags)
{
	int				*c;

	if ((flags & HISTORIC) == 0)
		return (1);
	c = &(line_struct->current_historic);
	(*c)--;
	if (*c >= 0)
		routine_set_line(line_struct, c);
	else
	{
		*c = -1;
		routine_reset_line(line_struct);
	}
	return (1);
}

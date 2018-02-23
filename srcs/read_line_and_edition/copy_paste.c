/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:22:44 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:23:05 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		routine_copy_selected(t_line *line_struct)
{
	char	*l;
	int		len;
	int		index_start;
	int		start;
	int		stop;

	l = line_struct->line;
	start = line_struct->select.start;
	stop = line_struct->select.stop;
	index_start = ((start <= stop) ? start : stop);
	len = ABS(start - stop) + 1;
	if (line_struct->select.str)
	{
		free(line_struct->select.str);
		line_struct->select.str = NULL;
	}
	if ((line_struct->select.str = ft_strsub(l, index_start, len)) == NULL)
		exit_routine();
	line_struct->select.select_mode = 0;
	line_struct->select.start = -1;
	line_struct->select.stop = -1;
}

int				copy_selected(t_line *line_struct, int flags)
{
	(void)flags;
	if (line_struct->select.select_mode == 0)
	{
		if (line_struct->select.str)
		{
			free(line_struct->select.str);
			line_struct->select.str = NULL;
		}
		return (1);
	}
	routine_copy_selected(line_struct);
	update_term(line_struct, 0);
	return (1);
}

int				paste_selected(t_line *line_struct, int flags)
{
	char	*l;
	char	*sel;
	char	*new;
	int		nb_char;

	(void)flags;
	if (line_struct->select.str == NULL)
		return (1);
	l = line_struct->line;
	sel = line_struct->select.str;
	nb_char = line_struct->nb_char;
	new = (char *)ft_memalloc(sizeof(char) * (nb_char + ft_strlen(sel) + 1));
	if (!new)
		exit_routine();
	ft_strncat(new, l, (line_struct->cursor_pos));
	ft_strcat(new, sel);
	ft_strcat(new, &l[line_struct->cursor_pos]);
	line_struct->size = nb_char + ft_strlen(sel) + 1;
	line_struct->nb_char = nb_char + ft_strlen(sel);
	free(line_struct->line);
	line_struct->line = new;
	update_term(line_struct, 0);
	return (1);
}

int				select_mode(t_line *line_struct, int flags)
{
	(void)flags;
	if (line_struct->select.select_mode == 0)
	{
		line_struct->select.select_mode = 1;
		line_struct->select.start = line_struct->cursor_pos;
		line_struct->select.stop = line_struct->cursor_pos;
	}
	else
	{
		line_struct->select.select_mode = 0;
		line_struct->select.start = -1;
		line_struct->select.stop = -1;
	}
	update_term(line_struct, 0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:32:04 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:53:57 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		down_line(t_line *line, int flags)
{
	char	*l;
	int		cp;

	(void)flags;
	l = line->line;
	cp = line->cursor_pos;
	if (ft_strchr(l, '\n'))
	{
		while (l[cp] && l[cp] != '\n')
			cp++;
		line->cursor_pos = l[cp] ? (cp + 1) : cp;
	}
	else if (line->cursor_pos + line->nb_col_term <= line->nb_char)
		line->cursor_pos = line->cursor_pos + line->nb_col_term;
	else
		line->cursor_pos = line->nb_char;
	update_term(line, 0);
	return (1);
}

int		up_line(t_line *line, int flags)
{
	char	*l;
	int		cp;

	(void)flags;
	l = line->line;
	cp = line->cursor_pos;
	if (ft_strchr(l, '\n'))
	{
		while (cp > 0 && l[cp] != '\n')
			cp--;
		line->cursor_pos = cp > 0 ? (cp - 1) : cp;
	}
	else if (line->cursor_pos - line->nb_col_term >= 0)
		line->cursor_pos = line->cursor_pos - line->nb_col_term;
	else
		line->cursor_pos = 0;
	update_term(line, 0);
	return (1);
}

int		move_home(t_line *line_struct, int flags)
{
	(void)flags;
	line_struct->cursor_pos = 0;
	update_term(line_struct, 0);
	return (1);
}

int		move_end(t_line *line_struct, int flags)
{
	(void)flags;
	line_struct->cursor_pos = line_struct->nb_char;
	update_term(line_struct, 0);
	return (1);
}

int		ft_delete_current_character(t_line *line_struct, int flags)
{
	char			*line;
	int				*cp;
	int				*n;

	(void)flags;
	if (line_struct->cursor_pos < line_struct->nb_char)
	{
		line = line_struct->line;
		cp = &(line_struct->cursor_pos);
		n = &(line_struct->nb_char);
		ft_memmove(&line[*cp], &line[(*cp) + 1], sizeof(char) * (*n - *cp));
		line[--(*n)] = 0;
		update_term(line_struct, 0);
	}
	return (1);
}

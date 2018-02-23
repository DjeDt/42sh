/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:30:54 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:53:39 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		move_left_word(t_line *line_struct, int flags)
{
	char	*l;
	int		cp_tmp;

	(void)flags;
	l = line_struct->line;
	cp_tmp = line_struct->cursor_pos;
	cp_tmp--;
	while (cp_tmp >= 0 && l[cp_tmp] == ' ')
		cp_tmp--;
	while (cp_tmp >= 0 && l[cp_tmp] != ' ')
		cp_tmp--;
	line_struct->cursor_pos = (cp_tmp + 1);
	if (line_struct->select.select_mode)
		line_struct->select.stop = line_struct->cursor_pos;
	update_term(line_struct, 0);
	return (1);
}

int		move_right_word(t_line *line_struct, int flags)
{
	char	*l;
	int		cp_tmp;

	(void)flags;
	l = line_struct->line;
	cp_tmp = line_struct->cursor_pos;
	while (l[cp_tmp] && l[cp_tmp] != ' ')
		cp_tmp++;
	while (l[cp_tmp] && l[cp_tmp] == ' ')
		cp_tmp++;
	line_struct->cursor_pos = cp_tmp;
	if (line_struct->select.select_mode)
		line_struct->select.stop = line_struct->cursor_pos;
	update_term(line_struct, 0);
	return (1);
}

int		move_left(t_line *line_struct, int flags)
{
	(void)flags;
	if (line_struct->cursor_pos > 0)
	{
		(line_struct->cursor_pos)--;
		if (line_struct->select.select_mode)
			line_struct->select.stop = line_struct->cursor_pos;
		update_term(line_struct, 0);
	}
	return (1);
}

int		move_right(t_line *line_struct, int flags)
{
	(void)flags;
	if (line_struct->cursor_pos < line_struct->nb_char)
	{
		(line_struct->cursor_pos)++;
		if (line_struct->select.select_mode)
			line_struct->select.stop = line_struct->cursor_pos;
		update_term(line_struct, 0);
	}
	return (1);
}

int		ft_delete_character(t_line *line_struct, int flags)
{
	char			*line;
	int				*cp;
	int				*n;

	(void)flags;
	line = line_struct->line;
	cp = &(line_struct->cursor_pos);
	n = &(line_struct->nb_char);
	if (*n == 0 || *cp == 0)
		return (1);
	(*cp)--;
	ft_memmove(&line[*cp], &line[(*cp) + 1], sizeof(char) * (*n - *cp));
	line[--(*n)] = 0;
	update_term(line_struct, 0);
	return (1);
}

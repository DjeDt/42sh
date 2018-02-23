/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:35:45 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:52:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			loop_replace_cursor(t_line *l, int cursor)
{
	int				i;
	int				j;
	t_term_line		t;

	while (l->cursor_pos != cursor)
	{
		i = l->cursor_pos;
		if (get_term_line(l, &t, i))
		{
			tputs(tgetstr("cr", NULL), 1, ft_putc);
			tputs(tgetstr("sr", NULL), (l->nb_line_term / 2), ft_putc);
			(l->current_line)--;
			if (!(l->current_line))
				j = -(l->len_prompt);
			else
				j = 0;
			while (j++ < t.nb_char)
				tputs(tgetstr("nd", NULL), 1, ft_putc);
		}
		else
			tputs(tgetstr("le", NULL), 1, ft_putc);
		(l->cursor_pos)--;
	}
	return ;
}

static void		routine_new_line(t_line *l, int *ncline, int *offset, int i)
{
	int		len_prompt;

	len_prompt = l->len_prompt;
	if ((i + len_prompt + *offset + 1) % l->nb_col_term == 0
		|| l->line[i] == '\n')
	{
		if (l->line[i] == '\n')
		{
			*offset = *offset + (l->nb_col_term - (*ncline + 1));
			if (l->current_line == 0)
				*offset = *offset - len_prompt;
			add_line(l, i + 1, *ncline);
			*ncline = 0;
		}
		else
		{
			add_line(l, i + 1, *ncline);
			*ncline = 0;
		}
		tputs(tgetstr("cr", NULL), 1, ft_putc);
		tputs(tgetstr("sf", NULL), (l->nb_line_term / 2), ft_putc);
		(l->current_line)++;
		(l->nb_line)++;
	}
	return ;
}

static void		loop_print_line(t_line *line_struct, int *offset, int *ncline)
{
	int		sel[2];
	char	c;
	int		i;

	sel[START] = line_struct->select.start;
	sel[STOP] = line_struct->select.stop;
	*ncline = 0;
	*offset = 0;
	i = 0;
	while (i < line_struct->nb_char)
	{
		c = line_struct->line[i];
		if (c != '\n')
		{
			if (i >= ((sel[START] <= sel[STOP]) ? sel[START] : sel[STOP])
				&& i <= ((sel[STOP] >= sel[START]) ? sel[STOP] : sel[START]))
				tputs(tgetstr("so", NULL), 1, ft_putc);
			ft_putc((int)c);
			tputs(tgetstr("se", NULL), 1, ft_putc);
			(*ncline)++;
		}
		routine_new_line(line_struct, ncline, offset, i);
		i++;
	}
	return ;
}

static void		routine_update_term(t_line *line_struct)
{
	int				cp;
	int				offset;
	int				ncline;

	cp = line_struct->cursor_pos;
	line_struct->cursor_pos = line_struct->nb_char;
	loop_print_line(line_struct, &offset, &ncline);
	loop_replace_cursor(line_struct, cp);
	free_term_line(line_struct);
	return ;
}

void			update_term(t_line *line_struct, int flags)
{
	(void)flags;
	line_struct->nb_col_term = get_nb_col_term();
	line_struct->nb_line_term = get_nb_line_term();
	while ((line_struct->current_line) != 0)
	{
		tputs(tgetstr("sr", NULL), (line_struct->nb_line_term / 2), ft_putc);
		(line_struct->current_line)--;
	}
	line_struct->nb_line = 0;
	tputs(tgetstr("cr", NULL), 1, ft_putc);
	tputs(tgetstr("cd", NULL), (line_struct->nb_line_term / 2), ft_putc);
	ft_putstr_fd(line_struct->prompt, STDOUT_FILENO);
	routine_update_term(line_struct);
	return ;
}

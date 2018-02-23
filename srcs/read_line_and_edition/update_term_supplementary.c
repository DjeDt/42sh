/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_term_supplementary.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:36:12 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:53:21 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		get_nb_col_term(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int		get_nb_line_term(void)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	return (w.ws_row);
}

void	add_line(t_line *line, int start_index, int nb_char)
{
	t_term_line		*n;
	t_term_line		e;
	int				len;

	len = line->nb_term_line;
	n = (t_term_line *)malloc(sizeof(t_term_line) * (len + 1));
	if (!n)
		exit_routine();
	ft_memcpy((void *)n, (void *)line->term_line, sizeof(t_term_line) * len);
	e.nb_char = nb_char;
	e.start_index = start_index;
	n[(line->nb_term_line)++] = e;
	if (line->term_line)
		free(line->term_line);
	line->term_line = n;
	return ;
}

void	free_term_line(t_line *line_struct)
{
	t_term_line		*t;
	int				s;

	t = line_struct->term_line;
	s = line_struct->nb_term_line;
	ft_bzero((void *)t, sizeof(t_term_line) * s);
	free(line_struct->term_line);
	line_struct->term_line = NULL;
	line_struct->nb_term_line = 0;
	return ;
}

int		get_term_line(t_line *line_struct, t_term_line *term_line, int index)
{
	t_term_line		*list;
	int				i;

	list = line_struct->term_line;
	i = 0;
	while (i < line_struct->nb_term_line)
	{
		if (list[i].start_index == index)
		{
			term_line->start_index = list[i].start_index;
			term_line->nb_char = list[i].nb_char;
			return (1);
		}
		i++;
	}
	term_line->start_index = -1;
	term_line->nb_char = -1;
	return (0);
}

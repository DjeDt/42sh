/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_read_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:22:28 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:55:45 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define INDEX_NCLINE 0
#define INDEX_OFFSET 1
#define INDEX_CURLINE 2
#define INDEX_STARTLINE 3

void	insert_char(t_line *line_struct, char c)
{
	char			*l;
	int				cp;
	int				nchar;

	l = line_struct->line;
	cp = line_struct->cursor_pos;
	nchar = line_struct->nb_char;
	if (c == '\n')
		cp = nchar;
	if (nchar)
		ft_memmove(&l[cp + 1], &l[cp], sizeof(char) * (nchar - cp));
	l[cp] = c;
	(line_struct->nb_char)++;
	(line_struct->cursor_pos)++;
	if (c != '\n')
		update_term(line_struct, 0);
	else
	{
		tputs(tgetstr("cr", NULL), 1, ft_putc);
		while ((line_struct->current_line)++ <= line_struct->nb_line)
			tputs(tgetstr("sf", NULL), line_struct->nb_col_term, ft_putc);
	}
	return ;
}

char	*ft_realloc(char *line, int size)
{
	char	*str;

	str = (char *)ft_memalloc(size);
	if (!str)
		exit_routine();
	ft_strcat(str, line);
	free(line);
	return (str);
}

void	add_char(t_line *line_struct, char c)
{
	if (line_struct->nb_char == (line_struct->size - 1))
	{
		line_struct->size = line_struct->size + BUF_SIZE;
		line_struct->line = ft_realloc(line_struct->line, line_struct->size);
	}
	insert_char(line_struct, c);
	return ;
}

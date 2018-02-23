/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 10:48:22 by jballang          #+#    #+#             */
/*   Updated: 2017/07/19 10:05:40 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_autocomplete_update(t_line *line_s, char *new, int len, int cursor)
{
	free(line_s->line);
	line_s->line = new;
	line_s->nb_char = len;
	line_s->size = len + 1;
	line_s->cursor_pos += cursor;
}

void	ft_autocomplete_append(t_line *line_s, char *new, char *start)
{
	char	*new_line;
	int		new_len;
	int		i;
	int		j;
	int		x;

	new_len = (int)(ft_strlen(new) + ft_strlen(line_s->line)\
				- ft_strlen(start));
	new_line = (char*)malloc(sizeof(char) * (new_len + 1));
	i = 0;
	j = 0;
	x = 0;
	while (line_s->line[i] && i < (line_s->cursor_pos - (int)ft_strlen(start)))
	{
		new_line[i] = line_s->line[i];
		i++;
	}
	x = i + ft_strlen(start);
	while (new[j])
		new_line[i++] = new[j++];
	while (line_s->line[x])
		new_line[i++] = line_s->line[x++];
	new_line[i] = '\0';
	ft_autocomplete_update(line_s, new_line, new_len,\
							(int)(ft_strlen(new) - ft_strlen(start)));
}

void	ft_autocomplete_propose(t_list *files, int col)
{
	int		max_len;
	int		j;
	int		per_line;

	default_terminal_mode();
	max_len = get_maxlen(files) + 2;
	per_line = col / max_len;
	j = 0;
	ft_putchar('\n');
	while (files)
	{
		if (j == per_line)
		{
			ft_putchar('\n');
			j = 0;
		}
		ft_putstr(files->content);
		while (max_len > (int)files->content_size++)
			ft_putchar(' ');
		files = files->next;
		if (files)
			j++;
	}
	ft_putchar('\n');
	raw_terminal_mode();
}

int		ft_autocomplete(t_line *line_struct, int flags)
{
	char	*last_word;

	(void)flags;
	last_word = ft_get_last_word(line_struct->line, line_struct->cursor_pos);
	if (!ft_first_word(line_struct->line, 0, 0) ||\
		!ft_isvalid(ft_last_char(line_struct->line)))
		ft_autocomplete_binary(line_struct, last_word);
	else if (ft_first_word(line_struct->line, 0, 0))
		ft_autocomplete_files(line_struct, last_word);
	free(last_word);
	return (1);
}

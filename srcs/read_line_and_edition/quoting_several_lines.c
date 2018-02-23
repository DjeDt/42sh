/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting_several_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:32:22 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/29 17:01:17 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define BACKSLASH 0
#define SINGLE 1
#define DOUBLE 2
#define LINECONT 3

static int		routine_b_line_ed(t_line *line_struct, int quote[4], int i)
{
	if ((!quote[BACKSLASH] && !quote[SINGLE] && !quote[DOUBLE])
		|| (!quote[BACKSLASH] && !quote[SINGLE]
		&& quote[DOUBLE] && (line_struct->line[i + 1] == '\n'
		|| line_struct->line[i + 1] == '"')))
	{
		if (line_struct->line[i + 1] == '\n' && !line_struct->line[i + 2])
			quote[LINECONT] = 1;
		quote[BACKSLASH] = 1;
		return (1);
	}
	return (0);
}

static int		cond_loop(t_line *line_struct, int quote[4], char c, int i)
{
	if (c == '\\')
	{
		if (routine_b_line_ed(line_struct, quote, i))
			return (1);
	}
	else if (c == '"')
	{
		if (quote[DOUBLE] && !quote[BACKSLASH] && !quote[SINGLE])
			quote[DOUBLE] = 0;
		else if (!quote[BACKSLASH] && !quote[SINGLE])
			quote[DOUBLE] = 1;
	}
	else if (c == '\'')
	{
		if (quote[SINGLE] && !quote[BACKSLASH] && !quote[DOUBLE])
			quote[SINGLE] = 0;
		else if (!quote[BACKSLASH] && !quote[DOUBLE])
			quote[SINGLE] = 1;
	}
	return (0);
}

static void		loop_correctly_quoted(t_line *line_struct, int quote[4])
{
	int		i;
	char	c;

	i = 0;
	while ((c = line_struct->line[i]) != 0)
	{
		if (cond_loop(line_struct, quote, c, i) == 0)
			quote[BACKSLASH] = 0;
		i++;
	}
	return ;
}

int				is_correctly_quoted(t_line *line_struct)
{
	int		quote[4];

	quote[BACKSLASH] = 0;
	quote[SINGLE] = 0;
	quote[DOUBLE] = 0;
	quote[LINECONT] = 0;
	loop_correctly_quoted(line_struct, quote);
	if (quote[BACKSLASH] || quote[SINGLE] || quote[DOUBLE]
		|| quote[LINECONT])
		return (0);
	else
		return (1);
}

void			quoting_several_lines(t_line *line_struct)
{
	char	*new;
	char	*tmp;

	while (!is_correctly_quoted(line_struct))
	{
		tmp = ft_read_line("> ", 0);
		if (tmp && !(*tmp))
		{
			free(tmp);
			ft_strclr(line_struct->line);
			return ;
		}
		if ((new = ft_strjoin(line_struct->line, tmp)) == NULL)
			exit_routine();
		free(line_struct->line);
		free(tmp);
		line_struct->line = new;
	}
	return ;
}

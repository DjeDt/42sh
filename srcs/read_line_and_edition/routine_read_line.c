/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_read_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:35:23 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/18 14:20:54 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	no_return_read_line(t_line *line_struct, char *buf, int flags)
{
	int		i;

	if (buf[0] == CHAR_WINCH)
		update_term(line_struct, 0);
	else
	{
		if (line_edition(line_struct, (char *)buf, flags) == 0)
		{
			i = 0;
			while (buf[i])
				add_char(line_struct, buf[i++]);
		}
	}
	return ;
}

void	ctrl_d_read_line(t_line *line_struct, char **l, int flags)
{
	(void)flags;
	free(line_struct->line);
	default_terminal_mode();
	signal_read_line(OFF);
	*l = NULL;
	return ;
}

void	backslash_read_line(t_line *line_struct, char **l, int flags)
{
	(void)flags;
	add_char(line_struct, '\n');
	if (flags & QUOTES)
		quoting_several_lines(line_struct);
	default_terminal_mode();
	signal_read_line(OFF);
	if (flags & HISTORIC)
		ft_historic(line_struct, ADD);
	*l = line_struct->line;
	return ;
}

void	print_prompt(t_line *line_struct, int flags)
{
	int		i;

	(void)flags;
	tputs(tgetstr("so", NULL), 1, ft_putc);
	ft_putchar_fd('%', STDOUT_FILENO);
	tputs(tgetstr("se", NULL), 1, ft_putc);
	i = 0;
	while (i < (line_struct->nb_col_term - 1))
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	tputs(tgetstr("cr", NULL), 1, ft_putc);
	ft_putstr_fd(line_struct->prompt, STDOUT_FILENO);
	return ;
}

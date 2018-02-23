/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:34:59 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/09/13 16:44:07 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	init_line(t_line *line_struct, char *prompt, int flags)
{
	line_struct->size = BUF_SIZE;
	line_struct->nb_char = 0;
	line_struct->cursor_pos = 0;
	if ((line_struct->line = (char *)ft_memalloc(BUF_SIZE)) == NULL)
		exit_routine();
	line_struct->current_line = 0;
	line_struct->nb_line = 0;
	line_struct->nb_col_term = get_nb_col_term();
	line_struct->nb_line_term = get_nb_line_term();
	line_struct->prompt = prompt;
	line_struct->len_prompt = ft_strlen(prompt);
	if (flags & HISTORIC)
		ft_historic(line_struct, INIT);
	line_struct->term_line = NULL;
	line_struct->nb_term_line = 0;
	line_struct->select.select_mode = 0;
	line_struct->select.start = -1;
	line_struct->select.stop = -1;
	line_struct->select.str = NULL;
}

void	ft_read(char *buf)
{
	int		ret;

	ft_bzero((void *)buf, sizeof(char) * MAX_KEY_LEN + 1);
	ret = read(0, buf, MAX_KEY_LEN);
	if (ret == -1)
	{
		ft_putendl_fd("42sh: I/O error quitting...", 2);
		exit(EXIT_FAILURE);
	}
}

int		condition_read_line(t_line *line_struct, char **l, char *b, int flags)
{
	int		ret;

	ret = 1;
	if (b[0] == CTRLD_ASCII && !(line_struct->line[0])
		&& (flags & NULL_CTRLD))
		ctrl_d_read_line(line_struct, l, flags);
	else if (b[0] == '\n')
		backslash_read_line(line_struct, l, flags);
	else if (b[0] == CHAR_REPRINT)
	{
		while (line_struct->current_line < line_struct->nb_line)
		{
			tputs(tgetstr("sf", NULL), 1, ft_putc);
			(line_struct->current_line)++;
		}
		ft_strclr(line_struct->line);
		*l = line_struct->line;
	}
	else
	{
		no_return_read_line(line_struct, b, flags);
		ret = 0;
	}
	return (ret);
}

char	*loop_read_line(t_line *line_struct, int flags)
{
	char	buf[MAX_KEY_LEN + 1];
	char	*l;

	while (42)
	{
		ft_read((char *)buf);
		if (condition_read_line(line_struct, &l, (char *)buf, flags))
		{
			if (line_struct->select.str)
				free(line_struct->select.str);
			return (l);
		}
	}
}

char	*ft_read_line(char *prompt, int flags)
{
	t_line		line_struct;
	char		*l;
	int			ret;

	signal_read_line(ON);
	if (isatty(STDIN_FILENO))
	{
		tc_init();
		init_line(&line_struct, prompt, flags);
		print_prompt(&line_struct, flags);
		l = loop_read_line(&line_struct, flags);
	}
	else
	{
		ret = get_next_line(STDIN_FILENO, &l);
		if (ret == -1)
		{
			ft_putendl_fd("42sh: I/O error quitting...", 2);
			exit(EXIT_FAILURE);
		}
	}
	signal_read_line(OFF);
	return (l);
}

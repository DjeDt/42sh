/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:11:59 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/28 15:39:22 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define OPTION(x) (options & x)
#define NO_NEWLINE 2
#define ESCAPE_CHAR 4

static int		get_options_supplementary(char c, int *options)
{
	if (c == 'n')
		*options |= NO_NEWLINE;
	else if (c == 'e')
		*options |= ESCAPE_CHAR;
	else
	{
		*options = 0;
		return (0);
	}
	return (1);
}

static void		get_options(int *options, char ***cmd_ptr)
{
	char	**command;
	int		i;
	int		j;

	command = *cmd_ptr;
	*options = 0;
	i = 0;
	while (command[i] && command[i][0] == '-')
	{
		j = 1;
		while (command[i][j])
		{
			if (get_options_supplementary(command[i][j], options) == 0)
				return ;
			j++;
		}
		(*cmd_ptr)++;
		i++;
	}
	return ;
}

static char		get_escape_char(char c, int *index)
{
	(*index)++;
	if (c == 'a')
		return ('\a');
	else if (c == 'b')
		return ('\b');
	else if (c == 'c')
		return ((char)-1);
	else if (c == 'e')
		return ('\e');
	else if (c == 'f')
		return ('\f');
	else if (c == 'n')
		return ('\n');
	else if (c == 'r')
		return ('\r');
	else if (c == 't')
		return ('\t');
	else if (c == 'v')
		return ('\v');
	else if (c == '\\')
		return ('\\');
	(*index)--;
	return ('\\');
}

static int		echo_putstr(char *line, int options)
{
	int		i;
	char	c;

	i = 0;
	while (line[i])
	{
		if (OPTION(ESCAPE_CHAR) && line[i] == '\\' && line[i + 1])
		{
			c = get_escape_char(line[i + 1], &i);
			if (c == (char)-1)
				return (0);
			else
				ft_putchar(c);
		}
		else
			ft_putchar(line[i]);
		i++;
	}
	return (1);
}

void			ft_echo(char **command, t_shell *shell)
{
	int		options;

	shell = (void *)shell;
	command++;
	get_options(&options, &command);
	while (*command)
	{
		if (echo_putstr(*command, options) == 0)
			return ;
		if (*(++command))
			ft_putchar(' ');
	}
	if (!(options & NO_NEWLINE))
		ft_putchar('\n');
	shell->executor->exit_code = 0;
	return ;
}

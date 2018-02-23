/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode_tc_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:35:34 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:36:40 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_putc(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (0);
}

void	raw_terminal_mode(void)
{
	struct termios	attr;

	if (!isatty(STDIN_FILENO))
		return ;
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~(ICANON | ECHO);
	attr.c_oflag &= ~(OPOST);
	attr.c_cc[VMIN] = 1;
	attr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	return ;
}

void	default_terminal_mode(void)
{
	struct termios	attr;

	if (!isatty(STDIN_FILENO))
		return ;
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag |= (ICANON | ECHO);
	attr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	return ;
}

void	tc_init(void)
{
	char			*term_env;

	if (!(term_env = getenv("TERM")))
		term_env = "xterm";
	if (tgetent(NULL, term_env) <= 0)
	{
		ft_putendl_fd("42sh: TERM value not valid, taking default...", 2);
		term_env = "xterm";
		if (tgetent(NULL, term_env) <= 0)
		{
			ft_putendl_fd("42sh: TERM value not valid, quitting...", 2);
			default_terminal_mode();
			exit(EXIT_FAILURE);
		}
	}
	raw_terminal_mode();
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:35:13 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:35:17 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	handle_winch(int sig)
{
	char	tmp[2];

	(void)sig;
	if (!isatty(STDIN_FILENO))
		return ;
	tmp[0] = CHAR_WINCH;
	tmp[1] = '\0';
	ioctl(STDIN_FILENO, TIOCSTI, (const char *)tmp);
	return ;
}

void	handle_sigint(int sig)
{
	char	tmp[2];

	(void)sig;
	if (!isatty(STDIN_FILENO))
		return ;
	tmp[0] = CHAR_REPRINT;
	tmp[1] = '\0';
	tputs(tgetstr("sf", NULL), 1, ft_putc);
	tputs(tgetstr("cr", NULL), 1, ft_putc);
	ioctl(STDIN_FILENO, TIOCSTI, (const char *)tmp);
	return ;
}

void	signal_read_line(int on_off)
{
	if (on_off == ON)
	{
		signal(SIGWINCH, handle_winch);
		signal(SIGINT, handle_sigint);
	}
	else
	{
		signal(SIGWINCH, SIG_IGN);
		signal(SIGINT, SIG_IGN);
	}
	return ;
}

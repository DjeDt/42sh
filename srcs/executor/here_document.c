/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:14:26 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:14:29 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define HEREDOC_FLAGS O_WRONLY | O_CREAT | O_TRUNC | O_APPEND

void	here_document(t_icode *simple_command, t_shell *shell)
{
	char	**heredoc;
	int		fd;
	int		i;

	heredoc = simple_command->heredoc;
	fd = open("/tmp/.42sh_heredoc", HEREDOC_FLAGS, 0644);
	if (fd == -1)
	{
		add_error_exec("42sh: could not open a heredoc", shell->executor);
		return ;
	}
	i = 0;
	while (i < simple_command->nb_heredoc)
		ft_putstr_fd(heredoc[i++], fd);
	close(fd);
	fd = open("/tmp/.42sh_heredoc", O_RDONLY);
	if (fd == -1)
	{
		add_error_exec("42sh: could not open a heredoc", shell->executor);
		return ;
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return ;
}

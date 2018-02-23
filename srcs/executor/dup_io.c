/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:13:46 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:13:50 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define SRC_FD 0
#define DST_FD 1

void	dup_input(t_icode *simple_command, int current_index, t_shell *shell)
{
	t_icode			*src_node;
	t_icode			*dest_node;
	int				fd[2];
	struct stat		buf;

	if (current_index > 0)
		src_node = simple_command->children[current_index - 1];
	else
		src_node = NULL;
	dest_node = simple_command->children[current_index + 1];
	if (src_node && src_node->type == _IO_NUMBER)
		fd[SRC_FD] = ft_atoi(src_node->value);
	else
		fd[SRC_FD] = STDIN_FILENO;
	if (ft_strncmp("-", dest_node->value, ft_strlen(dest_node->value)) == 0)
		close(fd[SRC_FD]);
	else
	{
		fd[DST_FD] = ft_atoi(dest_node->value);
		if (fstat(fd[DST_FD], &buf) == -1)
			add_error_exec("42sh: bad file descriptor", shell->executor);
		else
			dup2(fd[DST_FD], fd[SRC_FD]);
	}
	return ;
}

void	dup_output(t_icode *simple_command, int current_index, t_shell *shell)
{
	t_icode			*src_node;
	t_icode			*dest_node;
	int				fd[2];
	struct stat		buf;

	if (current_index > 0)
		src_node = simple_command->children[current_index - 1];
	else
		src_node = NULL;
	dest_node = simple_command->children[current_index + 1];
	if (src_node && src_node->type == _IO_NUMBER)
		fd[SRC_FD] = ft_atoi(src_node->value);
	else
		fd[SRC_FD] = STDOUT_FILENO;
	if (ft_strncmp("-", dest_node->value, ft_strlen(dest_node->value)) == 0)
		close(fd[SRC_FD]);
	else
	{
		fd[DST_FD] = ft_atoi(dest_node->value);
		if (fstat(fd[DST_FD], &buf) == -1)
			add_error_exec("42sh: bad file descriptor", shell->executor);
		else
			dup2(fd[DST_FD], fd[SRC_FD]);
	}
	return ;
}

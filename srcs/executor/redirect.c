/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:14:35 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/12 13:46:34 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	redirect(t_icode *simple_command, int current_index, t_shell *s)
{
	t_icode		*redirect_operator;

	redirect_operator = simple_command->children[current_index];
	if (redirect_operator->type == _GREAT)
		redirect_output(simple_command, current_index, s);
	else if (redirect_operator->type == _LESS)
		redirect_input(simple_command, current_index, s);
	else if (redirect_operator->type == _DGREAT)
		redirect_output_append(simple_command, current_index, s);
	else if (redirect_operator->type == _DLESS)
		here_document(simple_command, s);
	else if (redirect_operator->type == _DUP_OUTPUT)
		dup_output(simple_command, current_index, s);
	else if (redirect_operator->type == _DUP_INPUT)
		dup_input(simple_command, current_index, s);
	else
		ft_putstr_fd("Operator not handled yet...", 2);
	return ;
}

void	redirect_output(t_icode *sc, int current_index, t_shell *shell)
{
	t_icode			*file;
	t_icode			*src_node;
	struct stat		buf;
	int				src_fd;
	int				fd;

	if (current_index > 0)
		src_node = sc->children[current_index - 1];
	else
		src_node = NULL;
	if (src_node && src_node->type == _IO_NUMBER)
		src_fd = ft_atoi(src_node->value);
	else
		src_fd = STDOUT_FILENO;
	file = sc->children[current_index + 1];
	fd = open(file->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fstat(fd, &buf) != -1 && (buf.st_mode & S_IFMT) == S_IFREG)
		dup2(fd, src_fd);
	else
		add_error_exec("42sh: bad file descriptor", shell->executor);
	if (fd != -1)
		close(fd);
	return ;
}

void	redirect_input(t_icode *sc, int current_index, t_shell *shell)
{
	t_icode			*file;
	t_icode			*src_node;
	struct stat		buf;
	int				src_fd;
	int				fd;

	if (current_index > 0)
		src_node = sc->children[current_index - 1];
	else
		src_node = NULL;
	if (src_node && src_node->type == _IO_NUMBER)
		src_fd = ft_atoi(src_node->value);
	else
		src_fd = STDIN_FILENO;
	file = sc->children[current_index + 1];
	fd = open(file->value, O_RDONLY, 0644);
	if (fstat(fd, &buf) != -1 && (buf.st_mode & S_IFMT) == S_IFREG)
		dup2(fd, src_fd);
	else
		add_error_exec("42sh: bad file descriptor", shell->executor);
	if (fd != -1)
		close(fd);
	return ;
}

void	redirect_output_append(t_icode *sc, int current_index, t_shell *shell)
{
	t_icode			*file;
	t_icode			*src_node;
	struct stat		buf;
	int				src_fd;
	int				fd;

	if (current_index > 0)
		src_node = sc->children[current_index - 1];
	else
		src_node = NULL;
	if (src_node && src_node->type == _IO_NUMBER)
		src_fd = ft_atoi(src_node->value);
	else
		src_fd = STDOUT_FILENO;
	file = sc->children[current_index + 1];
	fd = open(file->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fstat(fd, &buf) != -1 && (buf.st_mode & S_IFMT) == S_IFREG)
		dup2(fd, src_fd);
	else
		add_error_exec("42sh: bad file descriptor", shell->executor);
	if (fd != -1)
		close(fd);
	return ;
}

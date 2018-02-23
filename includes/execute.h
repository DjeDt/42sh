/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:47:04 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:47:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

t_exec	*allocate_executor(void);
void	free_executor(t_exec *exec);
void	print_exec_error(t_exec *exec);
void	add_error_exec(char *error_msg, t_exec *e);
void	execute(t_shell *shell);
void	execute_complete_command(t_icode *root, t_shell *shell);
void	execute_command(t_icode *root, int index, t_shell *s);
void	execute_simple_command(t_icode *simple_command, t_shell *shell);
void	execute_list(t_icode *root, t_shell *shell);
void	execute_subshell(t_icode *subshell, t_shell *shell);
void	redirect(t_icode *simple_command, int current_index, t_shell *s);
void	wait_function(int pid, t_shell *shell);
void	routine_pipe_child(int pipe[2], int i, int read_pipe, t_icode *root);
void	routine_exec(t_icode *simple_command, t_shell *shell);
char	*find_command(char *cmd, t_shell *shell);
void	here_document(t_icode *simple_command, t_shell *shell);
void	redirect(t_icode *simple_command, int current_index, t_shell *s);
void	redirect_output(t_icode *sc, int current_index, t_shell *shell);
void	redirect_output_append(t_icode *sc, int current_index, t_shell *shell);
void	redirect_input(t_icode *sc, int current_index, t_shell *shell);
void	dup_output(t_icode *simple_command, int current_index, t_shell *shell);
void	dup_input(t_icode *simple_command, int current_index, t_shell *shell);
#endif

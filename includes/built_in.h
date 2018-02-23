/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:40:46 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:40:47 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

void	ft_cd(char **command, t_shell *shell);
char	*get_env(char *env_name, t_shell *shell);
void	ft_env(char **command, t_shell *shell);
void	clear_env(t_shell *shell);
void	ft_setenv(char **command, t_shell *shell);
void	ft_unsetenv(char **command, t_shell *shell);
void	ft_putenv(char *line, t_shell *shell);
void	ft_print_env(t_shell *shell);
void	ft_echo(char **command, t_shell *shell);
void	exit_built_in(char **command, t_shell *shell);
void	error_env(char c);
#endif

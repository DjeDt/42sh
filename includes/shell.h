/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:04:20 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 16:04:41 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

t_shell			*allocate_shell(int ac, char **argv, char *envp[]);
int				get_term_fd(int flag);
void			free_shell(t_shell *shell);
#endif

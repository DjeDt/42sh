/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermediate_code.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:36:18 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 16:36:19 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERMEDIATE_CODE_H
# define INTERMEDIATE_CODE_H
# define _COMPLETE_COMMAND 20
# define _LIST 21
# define _AND_OR 22
# define _SIMPLE_COMMAND 23
# define _SUBSHELL 24
# define _REDIRECT_LIST 25

# define _BUILT_IN 2
# define _CD 8
# define _EXIT 16
# define _ENV 32
# define _SETENV 64
# define _UNSETENV 128
# define _ECHO 256
# define _BINARY 4

# define _COMMAND 26
# define _FILE 27

t_icode		*allocate_node(int type, char *value);
void		add_child(t_icode *p, t_icode *child);
#endif

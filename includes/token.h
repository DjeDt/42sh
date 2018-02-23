/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:44:25 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:44:28 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define _WORD 1
# define _ASSIGNEMENT_WORD 2
# define _NAME 3
# define _NEWLINE 4
# define _IO_NUMBER 5

# define _LESS 6
# define _GREAT 7
# define _DLESS 8
# define _DGREAT 9
# define _DUP_OUTPUT 10
# define _DUP_INPUT 11
# define _PIPE 12
# define _AND_IF 13
# define _OR_IF 14
# define _SEP 15
# define _OPEN_SUBSHELL 16
# define _CLOSE_SUBSHELL 17

# define _EOF 18
# define _EOL 19

t_token		*allocate_token(void);
t_token		*clean_token(t_token *token);
#endif

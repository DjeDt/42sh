/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:44:51 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:44:56 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

t_source	*allocate_source(t_shell *shell);
char		current_char(t_source *source);
void		get_input(t_source *source);
char		next_char(t_source *source);
char		peek_char(t_source *source);
void		clean_source(t_source *source);
#endif

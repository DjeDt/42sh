/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_read_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:50:48 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 16:04:01 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_READ_LINE_H
# define STRUCT_READ_LINE_H

typedef struct	s_select
{
	int		select_mode;
	int		start;
	int		stop;
	char	*str;
}				t_select;

typedef struct	s_term_line
{
	int		start_index;
	int		nb_char;
	int		flag;
}				t_term_line;

typedef struct	s_line
{
	char			*line;
	int				nb_char;
	int				cursor_pos;
	int				size;
	int				current_line;
	int				nb_line;
	int				nb_col_term;
	int				nb_line_term;
	char			*prompt;
	int				len_prompt;
	char			**historic;
	int				current_historic;
	int				len_historic;
	t_term_line		*term_line;
	int				nb_term_line;
	t_select		select;
}				t_line;
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:00:02 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 16:00:04 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SH_H
# define STRUCT_SH_H

typedef struct	s_source
{
	char	*line;
	int		current_pos;
	int		file_fd;
}				t_source;

typedef struct	s_token
{
	char	*str;
	int		type;
	int		positon;
}				t_token;

typedef struct	s_quotes_state
{
	int		squotes;
	int		dquotes;
	int		backslash;
}				t_quotes_state;

typedef struct	s_lexer
{
	t_token			*current_token;
	t_source		*source;
	t_quotes_state	*state;
}				t_lexer;

typedef struct	s_icode
{
	int				type;
	char			*value;
	int				command_type;
	char			**command;
	int				hidden;
	struct s_icode	**children;
	int				nb_children;
	char			**heredoc;
	int				nb_heredoc;
}				t_icode;

typedef struct	s_parser
{
	t_lexer		*lexer;
	t_icode		*tree;
	char		**error;
	int			nb_error;
}				t_parser;

typedef struct	s_exec
{
	char	**error;
	int		exit_code;
	int		nb_err;
}				t_exec;

typedef struct	s_shell
{
	t_parser	*parser;
	t_exec		*executor;
	int			term_fd;
	int			file_fd;
	char		**env;
	int			nb_var_env;
}				t_shell;
#endif

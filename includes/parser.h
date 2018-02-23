/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:34:16 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/08/16 09:41:20 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define TOKEN_STR lexer->current_token->str
# define TOKEN_TYPE lexer->current_token->type

t_parser	*allocate_parser(t_shell *shell);
void		parse(t_shell *shell);
void		free_parser(t_parser *parser);
void		free_tab(char **tab_cmd);
t_icode		*parse_complete_command(t_lexer *lexer, t_shell *shell);
t_icode		*parse_list(t_lexer *lexer, t_shell *shell);
t_icode		*parse_and_or(t_lexer *lexer, t_shell *shell);
t_icode		*parse_pipeline(t_lexer *lexer, t_shell *shell);
t_icode		*parse_command(t_lexer *lexer, t_shell *shell);
t_icode		*parse_simple_command(t_lexer *lexer, t_shell *shell);
t_icode		*parse_subshell(t_lexer *lexer, t_shell *shell);
int			is_start_command(t_lexer *lexer);
int			is_end_command(t_lexer *lexer);
int			is_end_pipeline(t_lexer *lexer);
int			is_end_and_or(t_lexer *lexer);
void		init_type_do_heredoc(t_icode *simple_command, t_shell *shell);
void		create_heredoc(t_icode *simple_command, t_shell *shell);
int			routine_create_heredoc(t_icode *sc, char *l, t_shell *s);
int			is_redirect_op(int type);
void		add_unexpected_token(t_lexer *lexer, t_shell *shell);
void		print_parse_error(t_parser *parser);
void		free_error_list(t_parser *parser);
void		add_error(char *error_msg, t_parser *parser);
void		error_simple_command(t_icode *sc, t_lexer *lexer, t_shell *shell);
void		error_pipeline(t_icode *pipeline, t_lexer *lexer, t_shell *shell);
void		error_logical_op(t_icode *cm, t_lexer *lexer, t_shell *shell);
#endif

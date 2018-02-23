/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:40:53 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:41:45 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef int(*t_routine_lexer)(t_token *, t_lexer *);
typedef int(*t_is_token)(t_lexer *);

t_lexer		*allocate_lexer(t_shell *shell);
t_token		*next_token(t_lexer *lexer);
t_token		*current_token(t_lexer *lexer);

void		extract_token(t_lexer *lexer);

int			routine_operator(t_token *token, t_lexer *lexer);
void		routine_operator_great(t_token *token, t_lexer *lexer);
void		routine_operator_less(t_token *token, t_lexer *lexer);
int			routine_blank(t_token *token, t_lexer *lexer);
int			routine_comma(t_token *token, t_lexer *lexer);
int			routine_pipe(t_token *token, t_lexer *lexer);
int			routine_andif(t_token *token, t_lexer *lexer);
int			routine_orif(t_token *token, t_lexer *lexer);
int			routine_eol(t_token *token, t_lexer *lexer);
int			routine_rest(t_token *token, t_lexer *lexer);
int			routine_open_subshell(t_token *token, t_lexer *lexer);
int			routine_close_subshell(t_token *token, t_lexer *lexer);

int			is_operator_token(t_lexer *lexer);
int			is_blank_token(t_lexer *lexer);
int			is_comma_token(t_lexer *lexer);
int			is_pipe_token(t_lexer *lexer);
int			is_and_if_token(t_lexer *lexer);
int			is_or_if_token(t_lexer *lexer);
int			is_open_subshell(t_lexer *lexer);
int			is_close_subshell(t_lexer *lexer);
int			is_eol_token(t_lexer *lexer);
int			is_rest_token(t_lexer *lexer);

int			change_quoting_state(t_lexer *lexer);
int			is_potential_quotes(char c);
int			quoted(t_quotes_state *state);
int			is_blank(char c);
char		*append_char(char *str, char c);
#endif

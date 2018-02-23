/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:15:41 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/29 16:58:27 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_quotes_state	*allocate_lexer_state(void)
{
	t_quotes_state	*state;

	state = (t_quotes_state *)malloc(sizeof(t_quotes_state));
	if (!state)
		exit_routine();
	state->backslash = 0;
	state->dquotes = 0;
	state->squotes = 0;
	return (state);
}

t_lexer			*allocate_lexer(t_shell *shell)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		exit_routine();
	lexer->source = allocate_source(shell);
	lexer->state = allocate_lexer_state();
	lexer->current_token = allocate_token();
	return (lexer);
}

t_token			*next_token(t_lexer *lexer)
{
	extract_token(lexer);
	return (lexer->current_token);
}

t_token			*current_token(t_lexer *lexer)
{
	if (lexer->current_token->type == 0)
		extract_token(lexer);
	return (lexer->current_token);
}

void			extract_token(t_lexer *lexer)
{
	static t_is_token		t[] = {is_operator_token, is_blank_token,
	is_comma_token, is_and_if_token, is_or_if_token, is_open_subshell,
	is_close_subshell, is_pipe_token, is_eol_token, is_rest_token};
	static t_routine_lexer	r[] = {routine_operator, routine_blank,
	routine_comma, routine_andif, routine_orif, routine_open_subshell,
	routine_close_subshell, routine_pipe, routine_eol, routine_rest};
	t_token					*token;
	int						i;

	token = clean_token(lexer->current_token);
	while (current_char(lexer->source) != 0)
	{
		if (change_quoting_state(lexer))
		{
			i = 0;
			while ((t[i])(lexer) == 0)
				i++;
			if ((r[i])(token, lexer))
				return ;
		}
	}
	if (token->type == 0)
		token->type = _EOF;
	return ;
}

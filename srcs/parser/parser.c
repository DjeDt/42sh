/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:20:35 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:20:37 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_parser	*allocate_parser(t_shell *shell)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		exit_routine();
	parser->lexer = allocate_lexer(shell);
	parser->tree = NULL;
	parser->error = NULL;
	parser->nb_error = 0;
	return (parser);
}

void		parse(t_shell *shell)
{
	t_parser	*parser;

	parser = shell->parser;
	parser->tree = parse_complete_command(parser->lexer, shell);
	return ;
}

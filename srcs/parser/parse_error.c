/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:20:24 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/08/16 09:41:58 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	routine_unexpected_token(char *str, t_lexer *lexer)
{
	if (TOKEN_TYPE == _SEP)
		ft_strcat(str, ";");
	else if (TOKEN_TYPE == _EOL)
		ft_strcat(str, "end of line");
	else if (TOKEN_TYPE == _EOF)
		ft_strcat(str, "end of input");
	else if (TOKEN_TYPE == _OPEN_SUBSHELL)
		ft_strcat(str, "(");
	else if (TOKEN_TYPE == _CLOSE_SUBSHELL)
		ft_strcat(str, ")");
	else if (TOKEN_TYPE == _PIPE)
		ft_strcat(str, "|");
	else if (TOKEN_TYPE == _OR_IF)
		ft_strcat(str, "||");
	else if (TOKEN_TYPE == _AND_IF)
		ft_strcat(str, "&&");
	else if (TOKEN_TYPE == _WORD)
		ft_strcat(str, "word");
	return ;
}

void	add_unexpected_token(t_lexer *lexer, t_shell *shell)
{
	char	*str;

	if ((str = ft_strnew(40)) == NULL)
		exit_routine();
	ft_strcat(str, "42sh: token ");
	routine_unexpected_token(str, lexer);
	ft_strcat(str, " unexpected");
	add_error(str, shell->parser);
	free(str);
	return ;
}

void	free_error_list(t_parser *parser)
{
	int		i;

	i = 0;
	while (i < parser->nb_error)
	{
		ft_strdel(&parser->error[i]);
		i++;
	}
	free(parser->error);
	parser->nb_error = 0;
	parser->error = NULL;
}

void	print_parse_error(t_parser *parser)
{
	int		i;

	i = 0;
	while (i < parser->nb_error && i < 1)
	{
		if (*(parser->error[i]))
			ft_putendl_fd(parser->error[i], 2);
		i++;
	}
}

void	add_error(char *error_msg, t_parser *parser)
{
	char	**err;
	int		nb;

	nb = parser->nb_error;
	err = (char **)ft_memalloc(sizeof(char *) * (nb + 1));
	if (!err)
		exit_routine();
	if (parser->error)
	{
		ft_memcpy((void *)err, (void *)parser->error, (sizeof(char *) * nb));
		free(parser->error);
	}
	if ((err[(parser->nb_error)++] = ft_strdup(error_msg)) == NULL)
		exit_routine();
	parser->error = err;
}

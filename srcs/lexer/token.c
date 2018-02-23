/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:16:37 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:16:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_token		*clean_token(t_token *token)
{
	if (token->str)
	{
		free(token->str);
		token->str = NULL;
	}
	token->type = 0;
	return (token);
}

t_token		*allocate_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		exit_routine();
	token->str = NULL;
	token->type = 0;
	return (token);
}

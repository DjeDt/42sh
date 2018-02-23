/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:15:15 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:15:35 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			is_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

int			is_potential_quotes(char c)
{
	if (c == '\'' || c == '"' || c == '\\')
		return (1);
	else
		return (0);
}

int			quoted(t_quotes_state *state)
{
	if (state->backslash == 0
		&& state->squotes == 0
		&& state->dquotes == 0)
		return (0);
	else
		return (1);
}

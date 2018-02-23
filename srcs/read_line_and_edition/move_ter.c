/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:32:13 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:32:14 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		return_one(t_line *line_struct, int flags)
{
	(void)flags;
	line_struct = (void *)line_struct;
	return (1);
}

int		return_zero(t_line *line_struct, int flags)
{
	(void)flags;
	line_struct = (void *)line_struct;
	return (0);
}

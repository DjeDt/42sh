/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_quater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:24:00 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/18 14:02:52 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_ctrl_d(char *buf)
{
	if (buf[0] == 4)
		return (1);
	else
		return (0);
}

int		is_tab(char *buf)
{
	if (buf[0] == 9)
		return (1);
	else
		return (0);
}

int		is_return_one(char *buf)
{
	buf = (void *)buf;
	return (1);
}

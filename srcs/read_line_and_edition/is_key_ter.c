/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_ter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:24:08 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:37:08 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_ctrl_w(char *buf)
{
	if (buf[0] == (char)23 && !buf[1])
		return (1);
	else
		return (0);
}

int		is_ctrl_b(char *buf)
{
	if (buf[0] == (char)2 && !buf[1])
		return (1);
	else
		return (0);
}

int		is_home(char *buf)
{
	static char		home[] = {27, 91, 72};
	static char		gnu_home[] = {27, 79, 72};

	if ((ft_memcmp((void *)home, (void *)buf, sizeof(char) * 3)) == 0
		|| (ft_memcmp((void *)gnu_home, (void *)buf, sizeof(char) * 3)) == 0)
		return (1);
	else
		return (0);
}

int		is_end(char *buf)
{
	static char		end[] = {27, 91, 70};
	static char		gnu_end[] = {27, 79, 70};

	if ((ft_memcmp((void *)end, (void *)buf, sizeof(char) * 3)) == 0
		|| (ft_memcmp((void *)gnu_end, (void *)buf, sizeof(char) * 3)) == 0)
		return (1);
	else
		return (0);
}

int		is_control_code(char *buf)
{
	if (buf[0] < (char)32)
		return (1);
	else
		return (0);
}

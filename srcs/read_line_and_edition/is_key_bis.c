/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:23:52 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:23:55 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_shift_left(char *buf)
{
	static char		shift_left[7] = {27, 91, 49, 59, 50, 68, 14};

	if ((ft_memcmp((void *)shift_left, (void *)buf, sizeof(char) * 6)) == 0)
		return (1);
	else
		return (0);
}

int		is_shift_right(char *buf)
{
	static char		shift_right[7] = {27, 91, 49, 59, 50, 67, 14};

	if ((ft_memcmp((void *)shift_right, (void *)buf, sizeof(char) * 6)) == 0)
		return (1);
	else
		return (0);
}

int		is_shift_up(char *buf)
{
	static char		shift_up[7] = {27, 91, 49, 59, 50, 65, 14};

	if ((ft_memcmp((void *)shift_up, (void *)buf, sizeof(char) * 6)) == 0)
		return (1);
	else
		return (0);
}

int		is_shift_down(char *buf)
{
	static char		shift_down[7] = {27, 91, 49, 59, 50, 66, 14};

	if ((ft_memcmp((void *)shift_down, (void *)buf, sizeof(char) * 6)) == 0)
		return (1);
	else
		return (0);
}

int		is_ctrl_a(char *buf)
{
	if (buf[0] == (char)1 && !buf[1])
		return (1);
	else
		return (0);
}

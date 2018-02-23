/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:23:38 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:23:42 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		is_left_key(char *buf)
{
	static char		*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kl", NULL);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buf, ft_strlen(arrow)) == 0)
		return (1);
	else
		return (0);
}

int		is_right_key(char *buf)
{
	static char		*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kr", NULL);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buf, ft_strlen(arrow)) == 0)
		return (1);
	else
		return (0);
}

int		is_delete_key(char *buf)
{
	if (buf[0] == 127)
		return (1);
	else
		return (0);
}

int		is_up_key(char *buf)
{
	static char		*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("ku", NULL);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buf, ft_strlen(arrow)) == 0)
		return (1);
	else
		return (0);
}

int		is_down_key(char *buf)
{
	static char		*arrow = NULL;

	if (arrow == NULL)
	{
		arrow = tgetstr("kd", NULL);
		arrow[1] = 91;
	}
	if (ft_memcmp((void *)arrow, (void *)buf, ft_strlen(arrow)) == 0)
		return (1);
	else
		return (0);
}

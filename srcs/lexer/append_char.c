/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:15:05 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/15 15:15:08 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*append_char(char *str, char c)
{
	char	*new_str;

	if (!str)
	{
		if ((new_str = ft_strnew(2)) == NULL)
			exit_routine();
	}
	else
	{
		if ((new_str = ft_strnew(ft_strlen(str) + 2)) == NULL)
			exit_routine();
		ft_strcat(new_str, str);
		free(str);
	}
	ft_strncat(new_str, &c, 1);
	return (new_str);
}

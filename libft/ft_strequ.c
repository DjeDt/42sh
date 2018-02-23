/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:17:00 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 12:35:56 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (s1 && s2)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		i = 0;
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			else
				i++;
		}
		return (1);
	}
	else
		return (0);
}

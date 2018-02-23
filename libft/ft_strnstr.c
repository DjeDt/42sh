/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:20:27 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/12 14:21:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_is_in(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	size_t	i;
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
	{
		str = (char *)big;
		return (str);
	}
	i = 0;
	while (big[i] && i + lenlittle <= len)
	{
		if (ft_is_in(&big[i], little) != 0)
		{
			str = (char *)&big[i];
			return (str);
		}
		else
			i++;
	}
	return (NULL);
}

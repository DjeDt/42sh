/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:59:22 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/16 10:07:17 by ebenaiss         ###   ########.fr       */
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

char		*ft_strstr(const char *big, const char *little)
{
	char	*str;
	size_t	i;

	if (ft_strlen(little) == 0)
	{
		str = (char *)big;
		return (str);
	}
	i = 0;
	while (big[i])
	{
		if (ft_is_in(&big[i], little) == 1)
		{
			str = (char *)&big[i];
			return (str);
		}
		else
			i++;
	}
	return (NULL);
}

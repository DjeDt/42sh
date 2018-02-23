/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:28:24 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 14:27:06 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_append(size_t index, char const *str, char *dest)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		dest[index] = str[i];
		index++;
		i++;
	}
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lenfirst;
	size_t	lensecond;

	if (s1 && s2)
	{
		lenfirst = ft_strlen(s1);
		lensecond = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (lenfirst + lensecond + 1));
		if (!str)
			return (NULL);
		str = ft_append(0, s1, str);
		str = ft_append(lenfirst, s2, str);
		str[lenfirst + lensecond] = '\0';
		return (str);
	}
	else
		return (NULL);
}

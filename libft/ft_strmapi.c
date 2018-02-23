/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:15:39 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 14:23:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	length;
	size_t	i;

	if (s)
	{
		length = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * length + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < length)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

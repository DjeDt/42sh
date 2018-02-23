/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:06:11 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/21 15:24:41 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:29:06 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/16 14:09:38 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			str = (char *)&s[i];
			return (str);
		}
		else
			i++;
	}
	if (c == '\0')
	{
		str = (char *)&s[i];
		return (str);
	}
	else
		return (NULL);
}

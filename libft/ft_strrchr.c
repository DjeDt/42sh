/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:44:06 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/16 14:20:20 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			str = (char *)&s[i];
			return (str);
		}
		else
			i--;
	}
	if (c == '\0')
	{
		str = (char *)&s[i];
		return (str);
	}
	else
		return (NULL);
}

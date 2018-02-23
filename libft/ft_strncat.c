/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:49:52 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/12 14:24:22 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	lens1;
	size_t	i;

	lens1 = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i])
	{
		s1[lens1] = s2[i];
		lens1++;
		i++;
	}
	s1[lens1] = '\0';
	return (s1);
}

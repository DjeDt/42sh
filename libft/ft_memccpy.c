/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:59:42 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 13:51:03 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strdst;
	unsigned char	*strsrc;

	strdst = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if ((strdst[i] = strsrc[i]) == (unsigned char)c)
			return (&strdst[i + 1]);
		else
			i++;
	}
	return (NULL);
}

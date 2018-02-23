/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:49:32 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/13 16:22:13 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strsrc;
	char	*strdst;
	int		i;

	strsrc = (char *)src;
	strdst = (char *)dst;
	if (strsrc < strdst)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			strdst[i] = strsrc[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	return (strdst);
}

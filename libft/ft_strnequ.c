/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:17:38 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 14:26:21 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 && s2)
	{
		i = 0;
		while (i < n && s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			else
				i++;
		}
		return (1);
	}
	else
		return (-1);
}

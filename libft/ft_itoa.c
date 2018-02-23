/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:22:34 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/17 14:18:09 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(int n)
{
	int	i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_special_case(char const *src)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (NULL);
	str[11] = '\0';
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

static char		*ft_allocate_in_consequence(char *str, int n, int i)
{
	if (n < 0)
	{
		str = (char *)malloc(sizeof(char) * (i + 2));
		if (!str)
			return (NULL);
		str[0] = '-';
		str[i + 1] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		str[i] = '\0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_count(n);
	str = NULL;
	str = ft_allocate_in_consequence(str, n, i);
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str = ft_special_case("-2147483648");
		return (str);
	}
	if (n < 0)
		n = -n;
	else
		i--;
	while (n >= 10)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	str[i] = n + 48;
	return (str);
}

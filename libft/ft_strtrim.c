/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:20:18 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/21 09:43:42 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i[2];

	if (!s)
		return (NULL);
	i[0] = ft_strlen(s) - 1;
	i[1] = 0;
	while ((s[i[1]] == ' ' || s[i[1]] == '\n' || s[i[1]] == '\t')
			&& s[i[1]])
		i[1]++;
	while ((s[i[0]] == ' ' || s[i[0]] == '\n' || s[i[0]] == '\t')
			&& i[0] > 0)
		i[0]--;
	if (i[0] < i[1])
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_strsub(s, i[1], i[0] + 1 - i[1]);
	return (str);
}

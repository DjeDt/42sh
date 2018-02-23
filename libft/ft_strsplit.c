/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:06:21 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/22 15:31:49 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_count_word(const char *s, char c)
{
	int		word;
	int		i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
			i++;
	}
	return (word);
}

static char		*ft_add_str(char *str, const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i[3];

	if (!s)
		return (NULL);
	i[2] = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i[2] + 1))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] != c)
		{
			if (!(tab[i[1]] = ft_add_str(tab[i[1]], &s[i[0]], c)))
				return (NULL);
			i[1]++;
			while (s[i[0]] && s[i[0]] != c)
				i[0]++;
		}
		else
			i[0]++;
	}
	tab[i[1]] = NULL;
	return (tab);
}

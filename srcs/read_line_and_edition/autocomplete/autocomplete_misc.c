/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_misc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:48:22 by jballang          #+#    #+#             */
/*   Updated: 2017/07/12 11:27:41 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_isvalid(char c)
{
	if (ft_isprint(c) && c != '|' && c != ';' && c != '&' && c != '>' &&\
		c != '<' && c != ' ' && c != '\t')
		return (1);
	return (0);
}

char	*ft_isvalidchr(char *str)
{
	char	*tmp;

	if ((tmp = ft_strrchr(str, '|')) != NULL)
		return (tmp);
	if ((tmp = ft_strrchr(str, ';')) != NULL)
		return (tmp);
	if ((tmp = ft_strrchr(str, '&')) != NULL)
		return (tmp);
	if ((tmp = ft_strrchr(str, '>')) != NULL)
		return (tmp);
	if ((tmp = ft_strrchr(str, '<')) != NULL)
		return (tmp);
	return (NULL);
}

char	ft_last_char(char *str)
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			c = str[i];
		i++;
	}
	return (c);
}

int		ft_first_word(char *str, int i, int d)
{
	char	*tmp;

	if ((tmp = ft_isvalidchr(str)) == NULL)
		tmp = str;
	else
		i = 1;
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	while (tmp[i] && ft_isvalid(tmp[i]))
	{
		d++;
		i++;
	}
	if (d < 1)
		return (0);
	d = 0;
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
	{
		d++;
		i++;
	}
	if (d > 0)
		return (1);
	return (0);
}

int		ft_isnot_dot(char *str)
{
	if ((ft_strncmp(str, ".", 1) != 0 || ft_strlen(str) > 1) &&\
		(ft_strncmp(str, "..", 2) != 0 || ft_strlen(str) > 2))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:30:14 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/02/16 11:18:42 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_gain_spaces(char **line, char **remain, int ret)
{
	if (**remain && ret == 0)
	{
		if (!(*line = ft_strdup(*remain)))
			return (-1);
		ft_strclr(*remain);
		return (1);
	}
	else
		return (2);
}

int		ft_free(char **tmp1, char **tmp2, char *buf, int i)
{
	if (tmp1 && tmp2 == NULL)
	{
		ft_strdel(tmp1);
		ft_strclr(buf);
		return (0);
	}
	if (tmp1)
		ft_strdel(tmp1);
	if (tmp2)
		ft_strdel(tmp2);
	ft_strcpy(buf, &buf[i + 1]);
	ft_strclr(ft_strchr(buf, 0));
	return (0);
}

int		check_remain(char **remain, char **line, char *buf)
{
	size_t	i;

	if (line == NULL)
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	if (*remain == NULL)
	{
		*remain = ft_memalloc(1);
		return (2);
	}
	if (**remain)
	{
		i = 0;
		while ((*remain)[i])
			if ((*remain)[i] == '\n')
			{
				*line = ft_strsub(*remain, 0, i);
				ft_strcpy(*remain, &((*remain)[i + 1]));
				return (1);
			}
			else
				i++;
	}
	return (2);
}

int		check_line(char **remain, char **line, char *buf)
{
	size_t	i;
	char	*t[2];

	if (ft_strchr(buf, '\n'))
	{
		i = 0;
		while (buf[i] != '\n')
			i++;
		t[0] = *remain;
		t[1] = ft_strsub(buf, 0, i);
		if (!(*line = ft_strjoin(t[0], t[1])))
			return (-1);
		ft_free(&(t[0]), &(t[1]), buf, i);
		if (!(*remain = ft_strdup(buf)))
			return (-1);
		return (1);
	}
	else
	{
		t[0] = *remain;
		if (!(*remain = ft_strjoin(*remain, buf)))
			return (-1);
		ft_free(&(t[0]), NULL, buf, 0);
	}
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*remain = NULL;
	int			ret[2];

	if ((ret[1] = check_remain(&remain, line, buf)) <= 1)
		return (ret[1]);
	if ((ret[0] = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if ((ret[1] = ft_gain_spaces(line, &remain, ret[0])) <= 1)
		return (ret[1]);
	while (ret[0] != 0)
		if ((ret[1] = check_line(&remain, line, buf)) <= 1)
			return (ret[1]);
		else if ((ret[0] = read(fd, buf, BUFF_SIZE)) <= 0)
		{
			if (ret[0] != 0)
				return (-1);
			*line = ft_strdup(remain);
			ft_strclr(remain);
			return (1);
		}
	line[0] = NULL;
	return (0);
}

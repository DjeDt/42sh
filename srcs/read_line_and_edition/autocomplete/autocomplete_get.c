/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:48:22 by jballang          #+#    #+#             */
/*   Updated: 2017/09/05 16:50:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*ft_get_last_word(char *str, int cursor_pos)
{
	int		i;
	int		j;
	int		max;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && str[i + 1] && i < (cursor_pos - 1))
		i++;
	if (!ft_isprint(str[i]))
		return (ft_strdup(" "));
	else
	{
		max = i;
		while (i > 0 && ft_isvalid(str[i]))
			i--;
		ret = ft_strnew(max - (i - 1));
		while (i <= max)
			ret[j++] = str[i++];
		return (ret);
	}
}

char	*ft_get_path(char *str)
{
	char	*path;
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && ft_strchr(&str[i], '/'))
		i++;
	path = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && ft_strchr(&str[i], '/'))
	{
		path[i] = str[i];
		i++;
	}
	path[i] = '\0';
	ret = ft_strtrim(path);
	free(path);
	return (ret);
}

char	*ft_get_start(char *str)
{
	char	*start;

	start = ft_strdup((ft_strrchr(str, '/') + 1));
	return (start);
}

void	ft_autocomplete_binary_get_path(t_line *line_struct, char *start,\
										char **binary_path, int i)
{
	DIR				*dir;
	struct dirent	*current_file;
	t_list			*files;

	files = NULL;
	while (binary_path[i])
	{
		if ((dir = opendir(binary_path[i])) != NULL)
		{
			while ((current_file = readdir(dir)) != NULL)
			{
				if (files)
					ft_autocomplete_binary_fill(&files, binary_path[i],\
						current_file->d_name, start);
				else
					files = ft_autocomplete_binary_fill(NULL, binary_path[i],\
						current_file->d_name, start);
			}
			closedir(dir);
		}
		free(binary_path[i++]);
	}
	free(binary_path);
	ft_autocomplete_binary_display(line_struct, &files, start, NULL);
}

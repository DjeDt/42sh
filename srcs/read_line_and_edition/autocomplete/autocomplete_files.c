/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:52:45 by jballang          #+#    #+#             */
/*   Updated: 2017/07/11 13:35:56 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		get_maxlen(t_list *files)
{
	t_list	*tmp;
	size_t	max;

	tmp = files;
	max = 0;
	while (tmp)
	{
		if (tmp->content_size > max)
			max = tmp->content_size;
		tmp = tmp->next;
	}
	return ((int)max);
}

void	ft_autocomplete_files_display(t_list *files, char *start,\
	t_line *line_struct, char *path)
{
	t_list	*tmp;
	int		count;

	count = ft_lstcount(&files);
	if (count > 0)
	{
		ft_lstsort(&files);
		tmp = files;
		if (count == 1)
		{
			ft_autocomplete_isdir(&files, path);
			ft_autocomplete_append(line_struct, files->content, start);
		}
		else
			ft_autocomplete_propose(tmp, line_struct->nb_col_term);
		ft_lstdel(&files, ft_del);
		update_term(line_struct, 0);
	}
}

void	ft_autocomplete_files_fill(char *path, char *start,\
									t_line *line_struct)
{
	DIR				*dir;
	struct dirent	*current_file;
	t_list			*files;
	size_t			start_len;

	files = NULL;
	start_len = ft_strlen(start);
	if ((dir = opendir(path)) != NULL)
	{
		while ((current_file = readdir(dir)))
		{
			if (ft_isnot_dot(current_file->d_name) &&\
				ft_strncmp(current_file->d_name, start, start_len) == 0)
			{
				if (files)
					ft_lstpush(&files, ft_lstnew(current_file->d_name,\
						ft_strlen(current_file->d_name)));
				else
					files = ft_lstnew(current_file->d_name,\
						ft_strlen(current_file->d_name));
			}
		}
		closedir(dir);
	}
	ft_autocomplete_files_display(files, start, line_struct, path);
}

void	ft_autocomplete_files(t_line *line_struct, char *last_word)
{
	char	*path;
	char	*start;

	start = NULL;
	if (ft_strchr(last_word, '/'))
	{
		path = ft_get_path(last_word);
		start = ft_get_start(last_word);
	}
	else
	{
		path = ft_strdup("./");
		start = ft_strtrim(last_word);
	}
	ft_autocomplete_files_fill(path, start, line_struct);
	free(path);
	if (start)
		free(start);
}

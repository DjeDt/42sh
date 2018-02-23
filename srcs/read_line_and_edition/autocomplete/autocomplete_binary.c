/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_binary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:54:31 by jballang          #+#    #+#             */
/*   Updated: 2017/07/18 10:03:12 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_list	*ft_autocomplete_binary_fill(t_list **files, char *binary_path,\
										char *filename, char *start)
{
	char		*tmp_path;
	char		*complete_path;
	struct stat	fstat;

	tmp_path = ft_strjoin(binary_path, "/");
	complete_path = ft_strjoin(tmp_path, filename);
	if (stat(complete_path, &fstat) == 0 && (fstat.st_mode & S_IXUSR))
	{
		if (ft_isnot_dot(filename) &&\
			(ft_strncmp(filename, start, ft_strlen(start)) == 0))
		{
			if (files)
				ft_lstpush(files, ft_lstnew(filename, ft_strlen(filename)));
			else
			{
				free(tmp_path);
				free(complete_path);
				return (ft_lstnew(filename, ft_strlen(filename)));
			}
		}
	}
	free(tmp_path);
	free(complete_path);
	return (NULL);
}

void	ft_autocomplete_binary_display(t_line *line_struct, t_list **files,\
										char *start, char *path)
{
	t_list	*tmp;
	int		count;

	count = ft_lstcount(files);
	ft_lstsort(files);
	tmp = *files;
	if (count == 1)
	{
		ft_autocomplete_binary_isdir(files, path);
		ft_autocomplete_append(line_struct, tmp->content, start);
	}
	else if (count > 0)
		ft_autocomplete_propose(tmp, line_struct->nb_col_term);
	ft_lstdel(files, ft_del);
	if (count > 0)
		update_term(line_struct, 0);
}

t_list	*ft_autocomplete_binary_fill_clasic(t_list **files, char *filename,\
											char *start, char *path)
{
	char		*tmp_path;
	char		*complete_path;
	struct stat	fstat;

	tmp_path = ft_strjoin(path, "/");
	complete_path = ft_strjoin(tmp_path, filename);
	if (stat(complete_path, &fstat) == 0 &&\
		(fstat.st_mode & S_IXUSR || S_ISDIR(fstat.st_mode)))
	{
		if (ft_isnot_dot(filename) &&\
			(ft_strncmp(filename, start, ft_strlen(start)) == 0))
		{
			if (files)
				ft_lstpush(files, ft_lstnew(filename, ft_strlen(filename)));
			else
			{
				free(tmp_path);
				free(complete_path);
				return (ft_lstnew(filename, ft_strlen(filename)));
			}
		}
	}
	free(tmp_path);
	free(complete_path);
	return (NULL);
}

void	ft_autocomplete_binary_classic(t_line *line_struct,\
										char *start, char *path)
{
	DIR				*dir;
	struct dirent	*current_file;
	t_list			*files;

	files = NULL;
	if ((dir = opendir(path)) != NULL)
	{
		while ((current_file = readdir(dir)) != NULL)
		{
			if (ft_isnot_dot(current_file->d_name) &&\
				ft_strncmp(current_file->d_name, start, ft_strlen(start)) == 0)
			{
				if (files)
					ft_autocomplete_binary_fill_clasic(&files,\
						current_file->d_name, start, path);
				else
					files = ft_autocomplete_binary_fill_clasic(NULL,\
						current_file->d_name, start, path);
			}
		}
		closedir(dir);
	}
	ft_autocomplete_binary_display(line_struct, &files, start, path);
}

void	ft_autocomplete_binary(t_line *line_struct, char *last_word)
{
	char		*path;
	char		*start;
	char		**binary_path;
	extern char	**environ;

	start = NULL;
	path = NULL;
	if (ft_strchr(last_word, '/'))
	{
		path = ft_get_path(last_word);
		start = ft_get_start(last_word);
		ft_autocomplete_binary_classic(line_struct, start, path);
	}
	else
	{
		binary_path = loop_path(environ);
		start = ft_strtrim(last_word);
		ft_autocomplete_binary_get_path(line_struct, start, binary_path, 0);
	}
	free(start);
	if (path)
		free(path);
}

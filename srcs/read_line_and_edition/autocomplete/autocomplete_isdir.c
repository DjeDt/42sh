/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_isdir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:48:22 by jballang          #+#    #+#             */
/*   Updated: 2017/07/12 11:27:41 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_autocomplete_binary_isdir(t_list **files, char *path)
{
	t_list		*tmp;
	char		*new;
	char		*complete_path;
	struct stat	path_stat;

	tmp = *files;
	complete_path = ft_strjoin(path, tmp->content);
	if ((stat(complete_path, &path_stat)) == 0 && S_ISDIR(path_stat.st_mode))
	{
		new = ft_strnew(ft_strlen(tmp->content) + 2);
		new = ft_strcat(new, tmp->content);
		new = ft_strcat(new, "/");
		free(tmp->content);
		tmp->content = new;
	}
	free(complete_path);
}

void	ft_autocomplete_isdir(t_list **files, char *path)
{
	t_list		*tmp;
	char		*new;
	char		*complete_path;
	char		*tmp_path;
	struct stat	path_stat;

	tmp = *files;
	tmp_path = ft_strjoin("./", path);
	complete_path = ft_strjoin(tmp_path, tmp->content);
	if ((stat(complete_path, &path_stat)) == 0 && S_ISDIR(path_stat.st_mode))
	{
		new = ft_strnew(ft_strlen(tmp->content) + 2);
		new = ft_strcat(new, tmp->content);
		new = ft_strcat(new, "/");
		free(tmp->content);
		tmp->content = new;
	}
	free(tmp_path);
	free(complete_path);
}

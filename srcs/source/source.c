/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:39:47 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/06/29 17:02:06 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_source	*allocate_source(t_shell *shell)
{
	t_source	*source;

	source = (t_source *)malloc(sizeof(t_source));
	if (!source)
		exit_routine();
	source->line = NULL;
	source->current_pos = -1;
	source->file_fd = shell->file_fd;
	return (source);
}

char		current_char(t_source *source)
{
	if (source->line == NULL)
		get_input(source);
	if (source->current_pos == -1)
		return (next_char(source));
	else
		return (source->line[source->current_pos]);
}

char		next_char(t_source *source)
{
	if (source->current_pos == -1 || source->line[source->current_pos])
		source->current_pos++;
	return (current_char(source));
}

char		peek_char(t_source *source)
{
	if (source->line[source->current_pos])
		return (source->line[source->current_pos + 1]);
	else
		return ((char)0);
}

void		clean_source(t_source *source)
{
	if (source->line)
	{
		free(source->line);
		source->line = NULL;
	}
	source->current_pos = -1;
	return ;
}

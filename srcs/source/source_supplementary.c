/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_supplementary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 15:28:14 by ebenaiss          #+#    #+#             */
/*   Updated: 2017/07/19 15:28:15 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#define FLAG_READ_LINE QUOTES | NULL_CTRLD | HISTORIC

void		get_input(t_source *source)
{
	if (source->file_fd != -1)
		dup2(source->file_fd, STDIN_FILENO);
	if ((source->line = ft_read_line("$> ", FLAG_READ_LINE)) == NULL)
		exit(EXIT_SUCCESS);
	return ;
}

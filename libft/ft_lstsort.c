/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:50:22 by jballang          #+#    #+#             */
/*   Updated: 2017/07/18 10:00:39 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstsort_swap(t_list **lst)
{
	t_list	*tmp;
	char	*content;
	int		size;

	tmp = *lst;
	content = ft_strdup(tmp->content);
	free(tmp->content);
	tmp->content = ft_strdup(tmp->next->content);
	free(tmp->next->content);
	tmp->next->content = ft_strdup(content);
	free(content);
	size = tmp->content_size;
	tmp->content_size = tmp->next->content_size;
	tmp->next->content_size = size;
}

void	ft_lstsort(t_list **alst)
{
	t_list	*tmp;
	int		bubble;

	bubble = 1;
	while (bubble == 1)
	{
		bubble = 0;
		tmp = *alst;
		while (tmp && tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				ft_lstsort_swap(&tmp);
				bubble = 1;
			}
			tmp = tmp->next;
		}
	}
}

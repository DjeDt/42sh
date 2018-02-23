/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:15:51 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/21 13:37:20 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_del(void *content, size_t content_len)
{
	if (content && content_len)
	{
		free(content);
		content = NULL;
		content_len = 0;
	}
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*nxt;

	ptr = *alst;
	while (ptr != NULL)
	{
		nxt = ptr->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = nxt;
	}
	*alst = NULL;
}

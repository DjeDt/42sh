/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:21:27 by jballang          #+#    #+#             */
/*   Updated: 2017/06/29 13:21:37 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst)
	{
		tmp = *alst;
		if (new)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

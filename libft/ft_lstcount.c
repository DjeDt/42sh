/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballang <jballang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:49:26 by jballang          #+#    #+#             */
/*   Updated: 2017/06/29 13:50:55 by jballang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list **alst)
{
	int		i;
	t_list	*lst;

	i = 0;
	if (alst)
	{
		lst = *alst;
		while (lst)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

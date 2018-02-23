/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:45:45 by ebenaiss          #+#    #+#             */
/*   Updated: 2016/11/08 15:15:41 by ebenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*empty_zone;

	empty_zone = malloc(size);
	if (empty_zone)
	{
		ft_bzero(empty_zone, size);
		return (empty_zone);
	}
	else
		return (NULL);
}

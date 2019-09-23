/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:12:38 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 18:02:37 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*c;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	c = mem;
	while (i < size)
	{
		c[i] = '\0';
		i++;
	}
	return (c);
}

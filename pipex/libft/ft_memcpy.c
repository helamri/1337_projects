/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:00:59 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:01:06 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	i = 0;
	csrc = (char *)src;
	cdest = (char *)dst;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:03:10 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:03:16 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tsrc;
	char	*tdst;
	size_t	i;

	i = -1;
	tsrc = (char *)src;
	tdst = (char *)dst;
	if (tsrc < tdst)
		while ((int)(--len) >= 0)
			*(tdst + len) = *(tsrc + len);
	else
		while (++i < len)
			*(tdst + i) = *(tsrc + i);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:45:57 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 18:12:06 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*vdest;
	char	*vsrc;

	vdest = (char *)dst;
	vsrc = (char *)src;
	if (vsrc == vdest)
		return (dst);
	if (vsrc < vdest)
	{
		vsrc = vsrc + len - 1;
		vdest = vdest + len - 1;
		while (len--)
		{
			*vdest-- = *vsrc--;
		}
	}
	else
	{
		while (len--)
			*vdest++ = *vsrc++;
	}
	return (dst);
}

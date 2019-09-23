/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:37:06 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 18:42:38 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sstr1;
	unsigned char	*sstr2;
	size_t			i;

	i = 0;
	sstr1 = (unsigned char *)s1;
	sstr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (++i < n && *sstr1 == *sstr2)
	{
		sstr1++;
		sstr2++;
	}
	return ((int)(*sstr1 - *sstr2));
}

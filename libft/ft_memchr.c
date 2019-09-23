/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:43:21 by helamri           #+#    #+#             */
/*   Updated: 2018/10/11 18:35:58 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sstr;
	size_t			i;

	i = 0;
	sstr = (unsigned char *)s;
	while (i < n)
	{
		if (*sstr == (unsigned char)c)
			return (sstr);
		sstr++;
		++i;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:00:25 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 19:00:28 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (s2 < s1)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}

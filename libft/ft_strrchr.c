/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:39:49 by helamri           #+#    #+#             */
/*   Updated: 2018/10/12 11:59:05 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sstr;

	sstr = 0;
	while (*s)
	{
		if (*s == c)
			sstr = (char *)s;
		s++;
	}
	if (sstr)
		return (sstr);
	if (c == '\0')
		return ((char *)s);
	return (0);
}

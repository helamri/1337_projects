/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:09:37 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 19:09:41 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[a])
	{
		while (haystack[a + b] == needle[b])
		{
			if (needle[b + 1] == '\0')
				return ((char *)haystack + a);
			b++;
		}
		b = 0;
		a++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:39:49 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 18:37:48 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	pos;
	int	i;

	if (*to_find == '\0')
		return ((char*)str);
	pos = 0;
	while (str[pos] && (size_t)pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[pos + i] == to_find[i]
					&& (size_t)(pos + i) < len)
				i++;
			if (to_find[i] == '\0')
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (0);
}

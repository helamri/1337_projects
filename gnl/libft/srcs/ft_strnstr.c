/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:19:43 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:20:08 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = -1;
	res = (char*)big;
	if (*little == '\0')
		return (res);
	while (res[++i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && len > i + j)
		{
			if (little[j + 1] == '\0')
				return (&res[i]);
			j++;
		}
	}
	return (NULL);
}

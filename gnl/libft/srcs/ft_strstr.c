/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:18:17 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:19:29 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	res = (char*)big;
	if (*little == '\0')
		return (res);
	while (res[++i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return (&res[i]);
			j++;
		}
	}
	return (NULL);
}

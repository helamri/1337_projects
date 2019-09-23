/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 14:44:28 by helamri           #+#    #+#             */
/*   Updated: 2018/10/12 12:41:29 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[j])
	{
		if (str[j] == to_find[0])
		{
			while (to_find[i] != '\0' && str[j + i] == to_find[i])
				i++;
			if (to_find[i] == '\0')
				return ((char *)&str[j]);
		}
		j++;
	}
	return (0);
}

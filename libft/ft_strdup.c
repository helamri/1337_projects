/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:00:49 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 17:53:16 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int				i;
	static char		*dup;
	char			*offset;

	i = 0;
	while (s[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return ((char *)NULL);
	offset = dup;
	while (*s)
	{
		*offset = *s;
		offset++;
		s++;
	}
	*offset = '\0';
	return (dup);
}

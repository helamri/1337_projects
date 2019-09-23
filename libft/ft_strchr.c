/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:59:26 by helamri           #+#    #+#             */
/*   Updated: 2018/10/12 11:30:11 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sstr;

	sstr = (char *)s;
	while (*sstr)
	{
		if (*sstr == c)
			return (sstr);
		sstr++;
	}
	if (c == '\0')
		return (sstr);
	return (0);
}

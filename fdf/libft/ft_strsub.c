/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:09:57 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 19:10:00 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (fresh == NULL)
		return (NULL);
	while (s[start] && i < len)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}

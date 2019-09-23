/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:16:57 by helamri           #+#    #+#             */
/*   Updated: 2018/10/15 14:29:47 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	size;

	if (s1 && s2)
		size = (size_t)(ft_strlen((char*)s1) + ft_strlen((char*)s2));
	else if (s1)
		size = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		size = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(fresh = ft_memalloc(size)))
		return (NULL);
	if (s1)
		fresh = ft_strcpy(fresh, (char*)s1);
	else
		fresh = ft_strcpy(fresh, (char*)s2);
	if (s1 && s2)
		fresh = ft_strcat(fresh, (char*)s2);
	return (fresh);
}

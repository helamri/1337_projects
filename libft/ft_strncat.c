/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:33:27 by helamri           #+#    #+#             */
/*   Updated: 2018/10/10 17:55:08 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int			dest_len;
	size_t		i;

	i = 0;
	dest_len = 0;
	while (s1[dest_len])
		dest_len++;
	while (i < n && s2[i])
	{
		s1[dest_len] = s2[i];
		dest_len++;
		i++;
	}
	s1[dest_len] = '\0';
	return (s1);
}

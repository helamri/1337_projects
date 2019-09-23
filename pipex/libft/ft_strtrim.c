/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 14:45:35 by helamri           #+#    #+#             */
/*   Updated: 2018/10/15 18:51:06 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*fresh;
	unsigned int		i;
	unsigned int		size;
	unsigned int		counter;

	if (s == 0)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	counter = ft_countfirst((char*)s, " \n\t");
	i = counter;
	if (size > counter)
		counter += ft_countlast((char*)s, " \n\t");
	size -= counter;
	if (!(fresh = ft_memalloc((size_t)size + 1)))
		return (NULL);
	fresh = ft_strncpy(fresh, (char*)s + i, size);
	return (fresh);
}

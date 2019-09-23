/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:27:26 by helamri           #+#    #+#             */
/*   Updated: 2018/10/15 10:43:22 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*ptr2;
	char	*fresh;

	if (s == 0 || !(fresh = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	ptr = (char*)s;
	ptr2 = fresh;
	while (*ptr)
		*(ptr2++) = f(*(ptr++));
	return (fresh);
}

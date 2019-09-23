/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:53:44 by helamri           #+#    #+#             */
/*   Updated: 2018/10/15 11:05:23 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	i = 0;
	if (s == 0 || !(fresh = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	while (s[i])
	{
		fresh[i] = f(i, s[i]);
		++i;
	}
	return (fresh);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:36:58 by helamri           #+#    #+#             */
/*   Updated: 2018/10/16 19:49:26 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*delim;

	if (s == 0 || c == 0)
		return (NULL);
	if (!(delim = ft_strnew(2)))
		return (NULL);
	delim[0] = c;
	return (ft_delimsplit((char*)s, delim));
}

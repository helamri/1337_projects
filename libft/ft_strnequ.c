/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:56:11 by helamri           #+#    #+#             */
/*   Updated: 2018/10/15 12:26:01 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (n == 0)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	nbr = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	if (nbr != 0)
		return (0);
	return (1);
}

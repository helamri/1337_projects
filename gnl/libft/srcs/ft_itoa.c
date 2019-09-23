/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 10:17:39 by helamri           #+#    #+#             */
/*   Updated: 2018/10/17 10:44:57 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nb_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

char			*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	index;
	unsigned int	size;

	if (nbr < 0)
		nb = (unsigned int)-nbr;
	else
		nb = (unsigned int)nbr;
	size = (unsigned int)ft_nb_size(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && (str[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + '0');
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + '0');
	str[size] = '\0';
	return (str);
}

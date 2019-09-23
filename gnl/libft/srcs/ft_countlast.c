/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:00:48 by helamri           #+#    #+#             */
/*   Updated: 2018/10/16 19:14:19 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countlast(char *str, char *white)
{
	int				i;
	unsigned int	size;
	unsigned int	counter;
	unsigned int	temp;

	i = 0;
	size = ft_strlen(str) - 1;
	counter = 0;
	while (str[size])
	{
		i = 0;
		temp = counter;
		while (white[i])
			if (white[i++] == str[size])
				counter++;
		if (counter == temp)
			return (counter);
		size--;
	}
	return (counter);
}

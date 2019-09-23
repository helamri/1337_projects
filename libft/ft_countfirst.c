/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countfirst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:57:01 by helamri           #+#    #+#             */
/*   Updated: 2018/10/16 19:15:04 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countfirst(char *str, char *white)
{
	int					i;
	char				*ptr;
	unsigned int		counter;
	unsigned int		temp;

	i = 0;
	counter = 0;
	ptr = str;
	while (*ptr)
	{
		i = 0;
		temp = counter;
		while (white[i])
			if (white[i++] == *ptr)
				counter++;
		if (counter == temp)
			return (counter);
		ptr++;
	}
	return (counter);
}

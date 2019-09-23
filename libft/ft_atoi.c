/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:54:18 by helamri           #+#    #+#             */
/*   Updated: 2018/10/12 15:01:43 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned int	n;
	int				nega;

	i = 0;
	j = 0;
	nega = 0;
	n = 0;
	while ((str[i] == 32) || (str[i] == 9) || (str[i] == 10) || (str[i] == 11)
			|| (str[i] == 12) || (str[i] == 13))
		i++;
	if (str[i] == 45)
		nega++;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (nega == 1)
		return (-n);
	else
		return ((int)n);
}

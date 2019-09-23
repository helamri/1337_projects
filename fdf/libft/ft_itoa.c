/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:56:28 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 18:56:35 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * ft_intsize(n) + 1);
	i = ft_intsize(n);
	if (result == NULL)
		return (NULL);
	result[i--] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

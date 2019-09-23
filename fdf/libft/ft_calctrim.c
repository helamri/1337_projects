/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:52:40 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 18:52:58 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calctrim(char const *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (str[i] && ft_fisblank(str[i]) == 1)
	{
		result++;
		i++;
	}
	if (result == (int)ft_strlen(str))
		return (0);
	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_fisblank(str[i]) == 1)
	{
		result++;
		i--;
	}
	return (ft_strlen(str) - result);
}

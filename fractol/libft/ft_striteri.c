/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:26:14 by helamri           #+#    #+#             */
/*   Updated: 2018/10/29 11:26:25 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int j;

	i = 0;
	if (s == NULL || *f == NULL)
		return ;
	j = ft_strlen(s);
	while (i < j)
	{
		(*f)(i, s + i);
		i++;
	}
}

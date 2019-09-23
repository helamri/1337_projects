/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:53:14 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 18:53:26 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			words++;
		i++;
	}
	return (words);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:09:00 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 19:09:02 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len && str[len] != (char)c)
		len--;
	if (str[len] == (char)c)
		return ((char *)&str[len]);
	return (NULL);
}

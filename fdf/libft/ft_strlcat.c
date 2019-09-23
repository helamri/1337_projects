/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:06:17 by helamri           #+#    #+#             */
/*   Updated: 2018/12/29 19:06:19 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t len;

	len = ft_strlen(dst);
	if (size <= len)
		return (size + ft_strlen(src));
	ft_strncat(dst, src, size - len - 1);
	return (len + ft_strlen(src));
}

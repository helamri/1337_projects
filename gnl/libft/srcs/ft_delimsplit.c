/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:41:58 by helamri           #+#    #+#             */
/*   Updated: 2018/10/16 19:48:58 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_is_separator(char c, char const *delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		if (c == delim[i])
			return (1);
		++i;
	}
	return (0);
}

static int		ft_count_words(char *str, const char *delim)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] && ft_is_separator(str[i], delim))
		++i;
	if (str[i] && !ft_is_separator(str[i], delim))
		count = 1;
	while (str[i])
	{
		if (!ft_is_separator(str[i], delim)
				&& ft_is_separator(str[i - 1], delim))
			++count;
		++i;
	}
	return (count);
}

static int		ft_word_size(char *str, char const *delim)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && !ft_is_separator(str[i], delim))
	{
		++size;
		++i;
	}
	return (size);
}

char			**ft_delimsplit(char *str, const char *delim)
{
	char	**fresh;
	int		i;
	int		j;
	int		index;

	if (!(fresh = (char**)malloc(sizeof(char*) *
			(ft_count_words(str, delim) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!ft_is_separator(str[i], delim))
		{
			if (index == -1 || ft_is_separator(str[i - 1], delim))
			{
				if (!(fresh[++index] = (char*)malloc(sizeof(char) *
						(ft_word_size(str + i, delim) + 1))))
					return (NULL);
				j = 0;
			}
			fresh[index][j] = str[i];
			fresh[index][++j] = '\0';
		}
	fresh[++index] = 0;
	return (fresh);
}

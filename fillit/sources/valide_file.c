/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:14:08 by hmney             #+#    #+#             */
/*   Updated: 2018/11/14 10:55:50 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_block(char *str, int counter)
{
	int i;
	int	hash_number;

	i = 0;
	hash_number = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hash_number++;
		if ((i % 5) < 4 && (str[i] != '.' && str[i] != '#'))
			return (0);
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (i == 19 && counter + 1 > 26)
			return (0);
		i++;
	}
	if (hash_number != 4)
		return (0);
	return (1);
}

int		valid_tetrimino(char *str)
{
	int i;
	int liens;

	i = 0;
	liens = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#')
			liens++;
		if (str[i] == '#' && str[i + 5] == '#')
			liens++;
		if (str[i] == '#' && str[i - 1] == '#')
			liens++;
		if (str[i] == '#' && str[i - 5] == '#')
			liens++;
		i++;
	}
	if (liens < 6)
		return (0);
	return (1);
}

int		valid_file(int fd, t_tetriminos **store)
{
	char	buf[21];
	char	c[2];
	int		counter;
	int		r;

	counter = 0;
	while ((r = read(fd, buf, 20)) > 0)
	{
		buf[r] = '\0';
		if (!(valid_block(buf, counter) && valid_tetrimino(buf)) || r != 20)
			return (0);
		store_tetrimino(store,
				initialize_tetrimino(get_tetrimino(buf, counter)));
		counter++;
		c[0] = '\0';
		if ((r = read(fd, c, 1)) > 0)
		{
			c[r] = '\0';
			if (c[0] != '\n')
				return (0);
		}
	}
	if (c[0] == '\n' || counter == 0)
		return (0);
	return (1);
}

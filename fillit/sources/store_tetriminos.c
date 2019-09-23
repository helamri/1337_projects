/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:58:06 by hmney             #+#    #+#             */
/*   Updated: 2018/11/14 10:55:20 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetriminos	*get_tetrimino(char *str, int counter)
{
	int				i;
	int				j;
	int				k;
	t_tetriminos	*new;

	i = 0;
	j = 0;
	k = 0;
	if ((new = (t_tetriminos *)malloc(sizeof(t_tetriminos))) == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			new->block[j].x = k;
			new->block[j].y = i % 5;
			j++;
		}
		if (str[i] == '\n')
			k++;
		i++;
	}
	new->alphabet = 'A' + counter;
	new->next = NULL;
	return (new);
}

t_tetriminos	*initialize_tetrimino(t_tetriminos *tetrimino)
{
	int		i;
	int		min_line;
	int		min_colonne;

	i = 0;
	min_line = tetrimino->block[i].x;
	min_colonne = tetrimino->block[i].y;
	while (i < 4)
	{
		tetrimino->block[i].x -= min_line;
		tetrimino->block[i].y -= min_colonne;
		i++;
	}
	return (tetrimino);
}

void			store_tetrimino(t_tetriminos **store, t_tetriminos *tetrimino)
{
	t_tetriminos *temp;

	if (*store == NULL)
		*store = tetrimino;
	else
	{
		temp = *store;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = tetrimino;
	}
}

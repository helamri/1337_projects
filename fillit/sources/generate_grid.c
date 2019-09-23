/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:09:58 by hmney             #+#    #+#             */
/*   Updated: 2018/11/13 21:37:54 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		list_length(t_tetriminos *begin_list)
{
	t_tetriminos	*temp;
	int				length;

	length = 0;
	temp = begin_list;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}

int		calcul_grid(t_tetriminos *store)
{
	int	size;
	int	result;

	size = 4 * list_length(store);
	result = 2;
	while (result * result < size)
		result++;
	return (result);
}

char	**create_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	if ((grid = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	grid[size] = 0;
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		grid[i][size] = '\0';
		while (j < size)
			grid[i][j++] = '.';
		i++;
	}
	return (grid);
}

void	print_result_final(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != 0)
	{
		ft_putendl(grid[i]);
		i++;
	}
}

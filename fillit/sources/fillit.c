/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:04:52 by hmney             #+#    #+#             */
/*   Updated: 2018/11/14 10:55:47 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetrimino(char **grid, t_tetriminos *tetrimino, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		grid[i + tetrimino->block[k].x][j + tetrimino->block[k].y] =
			tetrimino->alphabet;
		k++;
	}
}

void	delete_tetrimino(char **grid, t_tetriminos *tetrimino, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		grid[i + tetrimino->block[k].x][j + tetrimino->block[k].y] = '.';
		k++;
	}
}

int		check_place(char **grid, t_tetriminos *tetrimino, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (tetrimino->block[k].x + i < 0 ||
				tetrimino->block[k].x + i > (int)ft_strlen(*grid) - 1)
			return (0);
		if (tetrimino->block[k].y + j < 0 ||
				tetrimino->block[k].y + j > (int)ft_strlen(*grid) - 1)
			return (0);
		if (grid[i + tetrimino->block[k].x][j + tetrimino->block[k].y] != '.')
			return (0);
		k++;
	}
	return (1);
}

int		fillit(char **grid, t_tetriminos *tetriminos)
{
	int				i;
	int				j;
	t_tetriminos	*temp;

	temp = tetriminos;
	if (temp == NULL)
		return (1);
	i = -1;
	while (grid[++i] != 0)
	{
		j = -1;
		while (grid[i][++j] != '\0')
		{
			if (check_place(grid, tetriminos, i, j))
			{
				print_tetrimino(grid, tetriminos, i, j);
				if (fillit(grid, tetriminos->next))
					return (1);
				else
					delete_tetrimino(grid, tetriminos, i, j);
			}
		}
	}
	return (0);
}

void	re_fillit(char **grid, int size, t_tetriminos *store)
{
	while (1)
	{
		grid = create_grid(size);
		if (!fillit(grid, store))
			size++;
		else
			break ;
	}
	print_result_final(grid);
}

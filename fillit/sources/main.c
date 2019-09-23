/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:40:27 by hmney             #+#    #+#             */
/*   Updated: 2018/11/14 10:54:57 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				fd;
	int				size;
	char			**grid;
	t_tetriminos	*store;

	store = NULL;
	grid = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (valid_file(fd, &store))
		{
			size = calcul_grid(store);
			re_fillit(grid, size, store);
		}
		else
			ft_putendl("error");
		close(fd);
		return (0);
	}
	ft_putendl("usage: ./fillit file_path");
	return (0);
}

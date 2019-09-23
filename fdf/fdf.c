/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:49:35 by helamri           #+#    #+#             */
/*   Updated: 2019/02/11 14:11:33 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	initmap(t_map map)
{
	index_window(map);
	map.pr = 0;
	map.z = 1;
	map.zoom = (3000 / (map.height * map.width)) + 1;
	map.view = 185;
	map.color = WHITE;
	if (map.height >= 500)
		map.init.y = 100;
	else
		map.init.y = 350;
	map.init.x = 970;
	return (map);
}

int				main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = convert_file(argv[1]);
		map.mlx = mlx_init();
		map.win = mlx_new_window(map.mlx, 2000, 1200, "fdf");
		mlx_hook(map.win, 2, 1, key_hook, &map);
		map = initmap(map);
		mlx_loop(map.mlx);
		free(map.num);
		free(&map);
	}
	else
	{
		ft_putendl("usage : ./fdf file.fdf");
		exit(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:50:32 by helamri           #+#    #+#             */
/*   Updated: 2019/02/11 14:19:38 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_remote(int key, t_map *map)
{
	if (key == 69)
	{
		map->zoom++;
		map->init.y -= map->width;
	}
	else if (key == 78 && map->zoom > 1)
	{
		map->zoom--;
		map->init.y += map->width;
	}
	else if (key == 86)
		map->init.x -= 20;
	else if (key == 88)
		map->init.x += 20;
	else if (key == 91)
		map->init.y -= 20;
	else if (key == 84)
		map->init.y += 20;
	key_remote_two(key, map);
	key_remote_three(key, map);
	return (0);
}

void		colors(int key, t_map *map)
{
	if (key == 5)
		map->color = GREEN;
	if (key == 8)
		map->color = CYAN;
	if (key == 9)
		map->color = VIOLET;
	if (key == 11)
		map->color = BLUE;
	if (key == 13)
		map->color = WHITE;
	if (key == 4)
		index_window(*map);
}

int			deal_key(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win);
	key_remote(key, map);
	colors(key, map);
	if (key == 35)
		map->pr = 1;
	if (key == 34)
		map->pr = 0;
	if (map->pr == 1)
		parallel_projection(*map);
	if (map->pr == 0)
		iso_projection(*map);
	return (0);
}

int			iso_projection(t_map map)
{
	t_map	**xy;

	xy = (t_map**)malloc(sizeof(t_map*) * map.width);
	map.j = -1;
	while (++map.j < map.width)
	{
		xy[map.j] = (t_map*)malloc(sizeof(t_map) * map.height);
		map.i = -1;
		while (++map.i < map.height)
		{
			xy[map.j][map.i].x = (map.j - map.i) *
				map.zoom * map.view / 100 + map.init.x;
			xy[map.j][map.i].y = (map.j + map.i) *
				map.zoom * 1 + map.init.y - map.z * map.num[map.i][map.j];
			if (map.i != 0)
				ligne(map, xy, xy[map.j][map.i - 1].x, xy[map.j][map.i - 1].y);
			if (map.j != 0)
				ligne(map, xy, xy[map.j - 1][map.i].x, xy[map.j - 1][map.i].y);
		}
	}
	free_tab(xy, map.width);
	return (0);
}

int			parallel_projection(t_map map)
{
	t_map	**xy;

	xy = (t_map**)malloc(sizeof(t_map*) * map.width);
	map.j = -1;
	while (++map.j < map.width)
	{
		xy[map.j] = (t_map*)malloc(sizeof(t_map) * map.height);
		map.i = -1;
		while (++map.i < map.height)
		{
			xy[map.j][map.i].x = (map.j) *
				map.zoom * map.view / 150 + map.init.x;
			xy[map.j][map.i].y = (map.i) *
				map.zoom + map.init.y;
			if (map.i != 0)
				ligne(map, xy, xy[map.j][map.i - 1].x, xy[map.j][map.i - 1].y);
			if (map.j != 0)
				ligne(map, xy, xy[map.j - 1][map.i].x, xy[map.j - 1][map.i].y);
		}
	}
	free_tab(xy, map.width);
	return (0);
}

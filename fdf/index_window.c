/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:23:20 by helamri           #+#    #+#             */
/*   Updated: 2019/02/06 20:19:22 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	index_window(t_map map)
{
	mlx_string_put(map.mlx, map.win, 20, 20, WGREEN,
			"Press any key to continue");
	mlx_string_put(map.mlx, map.win, 20, 40, WGREEN,
			"---------------------------");
	mlx_string_put(map.mlx, map.win, 120, 80, ROSE, "Zoom");
	mlx_string_put(map.mlx, map.win, 120, 110, ROSE, "+ or -");
	mlx_string_put(map.mlx, map.win, 120, 150, VIOLET, "Height");
	mlx_string_put(map.mlx, map.win, 120, 180, VIOLET, "( or )");
	mlx_string_put(map.mlx, map.win, 120, 220, GREEN, "View");
	mlx_string_put(map.mlx, map.win, 120, 250, GREEN, "< or >");
	mlx_string_put(map.mlx, map.win, 120, 290, CYAN, "Colors");
	mlx_string_put(map.mlx, map.win, 120, 320, CYAN, "W G B V C");
	mlx_string_put(map.mlx, map.win, 120, 360, YELLOW, "x+ Moving");
	mlx_string_put(map.mlx, map.win, 120, 390, YELLOW, "1 2 3 6 9 8 7 4");
	mlx_string_put(map.mlx, map.win, 120, 430, WHITE, "ISO Projection");
	mlx_string_put(map.mlx, map.win, 120, 460, WHITE, "I");
	mlx_string_put(map.mlx, map.win, 120, 500, BLUE, "Parallel Projection");
	mlx_string_put(map.mlx, map.win, 120, 530, BLUE, "P");
	mlx_string_put(map.mlx, map.win, 120, 570, RED, "Show Help / Remove Help");
	mlx_string_put(map.mlx, map.win, 120, 600, RED, "H / Any Key");
	mlx_string_put(map.mlx, map.win, 120, 640, ORANGE, "Exit");
	mlx_string_put(map.mlx, map.win, 120, 670, ORANGE, "esc");
}

int		key_remote_two(int key, t_map *map)
{
	if (key == 53)
		exit(1);
	else if (key == 25)
		map->z--;
	else if (key == 29)
		map->z++;
	else if (key == 47)
		map->view += 20;
	else if (key == 43)
		map->view -= 20;
	return (0);
}

int		key_remote_three(int key, t_map *map)
{
	if (key == 92)
	{
		map->init.x += 20;
		map->init.y -= 20;
	}
	else if (key == 89)
	{
		map->init.x -= 20;
		map->init.y -= 20;
	}
	else if (key == 85)
	{
		map->init.x += 20;
		map->init.y += 20;
	}
	else if (key == 83)
	{
		map->init.x -= 20;
		map->init.y += 20;
	}
	return (0);
}

int		key_hook(int key, t_map *map)
{
	deal_key(key, map);
	colors(key, map);
	key_remote(key, map);
	key_remote_two(key, map);
	key_remote_three(key, map);
	return (0);
}

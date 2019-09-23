/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:50:16 by helamri           #+#    #+#             */
/*   Updated: 2019/02/07 12:23:12 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		dxbdy(t_ligne l, t_map map)
{
	l.index = 0;
	l.cumul = l.dx / 2;
	while (++l.index <= l.dx)
	{
		l.x += l.xinc;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yinc;
		}
		if ((map.num[map.i][map.j] > 5 || map.num[map.i][map.j] < -5)
				&& map.z > 0)
			map.color = RED;
		else if ((map.num[map.i][map.j] > 5 || map.num[map.i][map.j] < -5)
				&& map.z < 0)
			map.color = YELLOW;
		mlx_pixel_put(map.mlx, map.win, l.x, l.y, map.color);
	}
}

static void		dybdx(t_ligne l, t_map map)
{
	l.index = 0;
	l.cumul = l.dy / 2;
	while (++l.index <= l.dy)
	{
		l.y += l.yinc;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xinc;
		}
		if ((map.num[map.i][map.j] > 5 || map.num[map.i][map.j] < -5)
				&& map.z > 0)
			map.color = RED;
		else if ((map.num[map.i][map.j] > 5 || map.num[map.i][map.j] < -5)
				&& map.z < 0)
			map.color = YELLOW;
		mlx_pixel_put(map.mlx, map.win, l.x, l.y, map.color);
	}
}

void			ligne(t_map map, t_map **xy, int xf, int yf)
{
	t_ligne		l;

	l.x = xy[map.j][map.i].x;
	l.y = xy[map.j][map.i].y;
	l.dx = xf - xy[map.j][map.i].x;
	l.dy = yf - xy[map.j][map.i].y;
	l.xinc = (l.dx > 0) ? 1 : -1;
	l.yinc = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	if (l.dx > l.dy)
		dxbdy(l, map);
	else
		dybdx(l, map);
}

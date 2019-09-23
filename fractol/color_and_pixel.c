/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:00:05 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 10:37:27 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void				put_pxl(t_env *e, int x, int y, int color)
{
	int				i;

	i = (x * 4) + (y * e->s_line);
	e->pxl[i] = color;
	e->pxl[++i] = color >> 8;
	e->pxl[++i] = color >> 16;
}

unsigned int		get_color(int i, t_env *e)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (i == e->imax)
		return (e->color_max);
	r = e->psychedelic * i * e->cr;
	g = e->psychedelic * i * e->cg;
	b = e->psychedelic * i * e->cb;
	color = (r << 16) + (g << 8) + b;
	return (color++);
}

void				string_put(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, WHITE, "Quit = ESC");
	mlx_string_put(e->mlx, e->win, 10, 20, WHITE, "Red mode = 4");
	mlx_string_put(e->mlx, e->win, 10, 40, WHITE, "Blue mode = 6");
	mlx_string_put(e->mlx, e->win, 10, 60,
			WHITE, "Zoom = - or + or scrolling");
	mlx_string_put(e->mlx, e->win, 10, 80, WHITE, "Iteration = / or *");
	mlx_string_put(e->mlx, e->win, 10, 100, WHITE, "psychedelic = ( or )");
	mlx_string_put(e->mlx, e->win, 10, 120, WHITE, "Burningship = b");
	mlx_string_put(e->mlx, e->win, 10, 140, WHITE, "Mandelbrot = m");
	mlx_string_put(e->mlx, e->win, 10, 160, WHITE, "Julia = j");
	mlx_string_put(e->mlx, e->win, 10, 180, WHITE, "Dendrite = d");
	mlx_string_put(e->mlx, e->win, 10, 200, WHITE, "Three = t");
	mlx_string_put(e->mlx, e->win, 10, 220, WHITE, "Zoom auto = z");
	mlx_string_put(e->mlx, e->win, 10, 240, WHITE, "Reset = r");
}

int					mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 5)
	{
		e->x += x / 5;
		e->y += y / 5;
		e->z = e->z * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
		e->imax += 1;
	}
	if (button == 4 && e->z > 100)
	{
		e->x -= x / 5;
		e->y -= y / 5;
		e->z = e->z / 1.2;
		e->y = e->y / 1.2;
		e->x = e->x / 1.2;
		e->imax -= 1;
	}
	loop_hook(e);
	return (1);
}

int					mouse_move_hook(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->width || y < 0 || y >= e->height)
		return (0);
	if (e->fractal == julia)
	{
		e->crmove = (x - 450) / (double)450;
		e->cimove = (-y + 300) / (double)300;
	}
	e->fractal(e);
	string_put(e);
	return (1);
}

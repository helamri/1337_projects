/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:19:42 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 10:29:32 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	burningship(t_env *e)
{
	int	x;
	int	y;

	e->str = e->burningship;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->burningship->zr = 0;
			e->burningship->zi = 0;
			e->burningship->cr = (double)x / e->z - 2.1;
			e->burningship->ci = (double)y / e->z - 1.8;
			put_pxl(e, x - e->x, y - e->y,
					get_color(iteration(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	three(t_env *e)
{
	int	x;
	int	y;

	e->str = e->three;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->three->zr = 0;
			e->three->zi = 0;
			e->three->cr = (double)x / e->z - 2.1;
			e->three->ci = (double)y / e->z - 1.2;
			put_pxl(e, x - e->x, y - e->y,
					get_color(iteration(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	mandelbrot(t_env *e)
{
	int	x;
	int	y;

	e->str = e->mandelbrot;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->mandelbrot->zr = 0;
			e->mandelbrot->zi = 0;
			e->mandelbrot->cr = (double)x / e->z - 2.1;
			e->mandelbrot->ci = (double)y / e->z - 1.2;
			put_pxl(e, x - e->x, y - e->y,
					get_color(iteration(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	julia(t_env *e)
{
	int	x;
	int	y;

	e->str = e->julia;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->julia->zr = (double)x / e->z - 2.1;
			e->julia->zi = (double)y / e->z - 1.2;
			e->julia->cr = e->crmove;
			e->julia->ci = e->cimove;
			put_pxl(e, x - e->x, y - e->y,
					get_color(iteration(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	dendrite(t_env *e)
{
	int	x;
	int	y;

	e->str = e->dendrite;
	x = e->x;
	while (x < e->width + e->x)
	{
		y = e->y;
		while (y < e->height + e->y)
		{
			e->dendrite->zr = (double)x / e->z - 2.1;
			e->dendrite->zi = (double)y / e->z - 1.2;
			e->dendrite->cr = 0;
			e->dendrite->ci = 1;
			put_pxl(e, x - e->x, y - e->y,
					get_color(iteration(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

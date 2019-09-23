/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:23:10 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 10:05:24 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		key_hook_5(int keycode, t_env *e)
{
	if (keycode == 15)
	{
		e->imax = 75;
		e->psychedelic = 1;
		e->cr = 5;
		e->cg = 10;
		e->crmove = 0;
		e->cimove = 0;
		e->cb = 2;
		e->x = 1;
		e->y = 1;
		e->z = 250;
		e->color_max = 0x000000;
	}
	return (1);
}

int		key_hook_4(int keycode, t_env *e)
{
	if (keycode == 29)
		e->psychedelic = (e->psychedelic < 255) ? e->psychedelic + 1 : 1;
	if (keycode == 25)
		e->psychedelic = (e->psychedelic > 1) ? e->psychedelic - 1 : 255;
	if (keycode == 17)
	{
		e->fractal = three;
		key_hook_5(15, e);
	}
	if (keycode == 86)
	{
		e->cr = 10;
		e->cg = 2;
		e->cb = 5;
	}
	else if (keycode == 88)
	{
		e->cr = 2;
		e->cg = 5;
		e->cb = 10;
	}
	return (1);
}

int		key_hook_3(int keycode, t_env *e)
{
	if (keycode == 123)
		e->x -= 60;
	if (keycode == 124)
		e->x += 60;
	if (keycode == 126)
		e->y -= 60;
	if (keycode == 125)
		e->y += 60;
	if (keycode == 69)
	{
		e->z = e->z * 1.025;
		e->y = e->y * 1.025;
		e->x = e->x * 1.025;
		e->x += e->width / 80;
		e->y += e->height / 80;
	}
	if (keycode == 78 && e->z > 100)
	{
		e->z = e->z / 1.025;
		e->y = e->y / 1.025;
		e->x = e->x / 1.025;
		e->x -= e->width / 80;
		e->y -= e->height / 80;
	}
	return (1);
}

int		key_hook_2(int keycode, t_env *e)
{
	if (keycode == 67)
		e->imax += 10;
	if (keycode == 75)
		e->imax -= 10;
	if (keycode == 11)
	{
		e->fractal = burningship;
		key_hook_5(15, e);
	}
	if (keycode == 46)
	{
		e->fractal = mandelbrot;
		key_hook_5(15, e);
	}
	if (keycode == 38)
	{
		e->fractal = julia;
		key_hook_5(15, e);
	}
	if (keycode == 2)
	{
		e->fractal = dendrite;
		key_hook_5(15, e);
	}
	return (1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (keycode == 6)
		e->auto_zoom = (!(e->auto_zoom)) ? 1 : 0;
	key_hook_5(keycode, e);
	key_hook_4(keycode, e);
	key_hook_3(keycode, e);
	key_hook_2(keycode, e);
	string_put(e);
	loop_hook(e);
	return (1);
}

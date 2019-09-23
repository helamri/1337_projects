/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:20:22 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 09:21:53 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

t_fractol	*init_fract(void)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = 0;
	fract->ci = 0;
	fract->tmp = 0;
	return (fract);
}

int			init_env_fract(t_env *e)
{
	if (!(e->burningship = init_fract()))
		return (0);
	if (!(e->mandelbrot = init_fract()))
		return (0);
	if (!(e->julia = init_fract()))
		return (0);
	if (!(e->dendrite = init_fract()))
		return (0);
	if (!(e->three = init_fract()))
		return (0);
	return (1);
}

void		*init_env(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	e->x = 1;
	e->y = 1;
	e->z = 250;
	e->color_max = 0x000000;
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pxl = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	e->imax = 75;
	e->psychedelic = 1;
	e->cr = 5;
	e->cg = 10;
	e->cb = 2;
	if (!(init_env_fract(e)))
		return (NULL);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fract'ol");
	return (e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:13:50 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 10:25:02 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		arg(int ac, char **av, t_env *e)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage <filename> [burningship/mandelbrot/julia", 2);
		ft_putstr_fd("/dendrite/three]", 2);
		return (0);
	}
	if (ft_strcmp(av[1], "burningship") == 0)
		key_hook_2(11, e);
	if (ft_strcmp(av[1], "julia") == 0)
		key_hook_2(38, e);
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		key_hook_2(46, e);
	if (ft_strcmp(av[1], "dendrite") == 0)
		key_hook_2(2, e);
	if (ft_strcmp(av[1], "three") == 0)
		key_hook_4(17, e);
	if (e->fractal)
		return (1);
	ft_putstr_fd("Sorry <filename> can only be [burningship/mandelbrot", 2);
	ft_putstr_fd("/julia/dendrite/three]", 2);
	return (0);
}

void	auto_zoom(t_env *e)
{
	e->z = e->z * 1.025;
	e->y = e->y * 1.025;
	e->x = e->x * 1.025;
	e->x += e->width / 80;
	e->y += e->height / 80;
}

int		loop_hook(t_env *e)
{
	if (e->auto_zoom)
		auto_zoom(e);
	e->fractal(e);
	string_put(e);
	return (1);
}

int		iteration(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->imax && (e->str->zr * e->str->zr + e->str->zi *
			e->str->zi < 4))
	{
		e->str->tmp = e->str->zr;
		e->str->zr = e->str->zr * e->str->zr -
			e->str->zi * e->str->zi + e->str->cr;
		if (e->str == e->burningship)
			e->str->zi = 2 * fabsf(e->str->zi * e->str->tmp) +
				e->str->ci;
		else if (e->str == e->three)
			e->str->zi = -2 * e->str->zi * e->str->tmp +
				e->str->ci;
		else
			e->str->zi = 2 * e->str->zi * e->str->tmp +
				e->str->ci;
		i++;
	}
	return (i);
}

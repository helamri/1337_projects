/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:12:09 by helamri           #+#    #+#             */
/*   Updated: 2019/05/05 08:55:58 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		main(int ac, char **av)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))) || !arg(ac, av, e))
		return (0);
	if (!(init_env(e)))
	{
		free(e);
		exit(0);
	}
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_hook(e->win, 2, 1, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_move_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

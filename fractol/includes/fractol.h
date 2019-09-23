/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:15:20 by helamri           #+#    #+#             */
/*   Updated: 2019/05/15 09:22:14 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# define WIDTH 900
# define HEIGHT 600
# define WHITE 0xffffff
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pxl;
	int					bpp;
	int					s_line;
	int					ed;
	int					width;
	int					height;
	void				(*fractal)();
	int					z;
	int					x;
	int					y;
	int					psychedelic;
	int					imax;
	float				crmove;
	float				cimove;
	struct s_fractol	*burningship;
	struct s_fractol	*mandelbrot;
	struct s_fractol	*julia;
	struct s_fractol	*dendrite;
	struct s_fractol	*three;
	struct s_fractol	*str;
	int					auto_zoom;
	unsigned int		color_max;
	int					cr;
	int					cg;
	int					cb;
}				t_env;

typedef struct	s_fractol
{
	float		zr;
	float		zi;
	float		cr;
	float		ci;
	float		tmp;
}				t_fractol;

int				arg(int ac, char **av, t_env *e);
void			*init_env(t_env *e);
void			put_pxl(t_env *e, int x, int y, int color);
void			string_put(t_env *e);
unsigned int	get_color(int i, t_env *e);
int				iteration(t_env *e);
void			burningship(t_env *e);
void			mandelbrot(t_env *e);
void			three(t_env *e);
void			julia(t_env *e);
void			dendrite(t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook_2(int keycode, t_env *e);
int				key_hook_3(int keycode, t_env *e);
int				key_hook_4(int keycode, t_env *e);
int				key_hook_5(int keycode, t_env *e);
int				loop_hook(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_move_hook(int x, int y, t_env *e);

#endif

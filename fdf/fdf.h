/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helamri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:49:05 by helamri           #+#    #+#             */
/*   Updated: 2019/02/11 14:09:17 by helamri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 40
# include <sys/stat.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x2E86FD
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define VIOLET 0x8A2BE2
# define CYAN 0x00ffd4
# define WGREEN 0x8af945
# define ROSE 0xf945f3
# define ORANGE 0xf48c42

typedef	struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef	struct	s_map
{
	int			width;
	int			height;
	int			fd;
	char		*line;
	void		*mlx;
	void		*win;
	char		**tab;
	int			**num;
	int			x;
	int			y;
	int			z;
	int			i;
	int			j;
	int			dx;
	int			dy;
	int			pr;
	int			zoom;
	int			view;
	int			color;
	t_xy		init;
}				t_map;

typedef struct	s_ligne
{
	int			dx;
	int			dy;
	int			cumul;
	int			xinc;
	int			yinc;
	int			index;
	int			x;
	int			y;
}				t_ligne;

void			free_tab(t_map **xy, int width);
int				key_hook(int key, t_map *map);
int				get_next_line(const int fd, char **line);
void			index_window(t_map map);
int				get_x(int fd, char **line);
int				get_y(char **tab);
int				open_file(char *file);
t_map			convert_file(char *file);
int				deal_key(int key, void *param);
void			ligne(t_map map, t_map **xy, int xf, int yf);
int				iso_projection(t_map map);
int				parallel_projection(t_map map);
int				key_remote_two(int key, t_map *map);
int				key_remote_three(int key, t_map *map);
void			colors(int key, t_map *map);
int				key_remote(int key, t_map *map);
#endif

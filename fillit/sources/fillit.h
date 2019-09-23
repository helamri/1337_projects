/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:01:47 by hmney             #+#    #+#             */
/*   Updated: 2018/11/13 21:47:39 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct				s_positions
{
	int						x;
	int						y;
}							t_positions;

typedef struct				s_tetriminos
{
	t_positions				block[4];
	char					alphabet;
	struct s_tetriminos		*next;
}							t_tetriminos;

int							valid_block(char *str, int counter);
int							valid_tetrimino(char *str);
int							valid_file(int fd, t_tetriminos **store);
t_tetriminos				*get_tetrimino(char *str, int counter);
t_tetriminos				*initialize_tetrimino(t_tetriminos *tetrimino);
void						store_tetrimino(t_tetriminos **store,
		t_tetriminos *tetrimino);
int							list_length(t_tetriminos *begin_list);
int							calcul_grid(t_tetriminos *store);
char						**create_grid(int size);
void						print_tetrimino(char **grid,
		t_tetriminos *tetrimino, int i, int j);
void						delete_tetrimino(char **grid,
		t_tetriminos *tetrimino, int i, int j);
int							check_place(char **grid, t_tetriminos *tetrimino,
		int i, int j);
int							fillit(char **grid, t_tetriminos *tetriminos);
void						print_result_final(char **grid);
void						re_fillit(char **grid, int size,
		t_tetriminos *store);

#endif
